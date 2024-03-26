#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;
const ll INF = 1e18;

void dfs(int node, vector<int> &vis, vector<vector<int>> adj)
{

    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(it, vis, adj);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjFromSource(n + 1), adjFromDest(n + 1);
    vector<tuple<int, int, int>> edges(n + 1);
    vector<int> visFromSource(n + 1), visFromDest(n + 1);
    int a, b, x;
    for (int i = 0; i < m; i++)
    {

        cin >> a >> b >> x;

        adjFromSource[a].push_back(b);
        adjFromDest[b].push_back(a);

        edges.push_back({a, b, -x});
    }

    vector<ll> dist(n + 1, INF);
    dfs(1, visFromSource, adjFromSource);
    dfs(n, visFromDest, adjFromDest);

    // for(auto it: dist) 
    //     cout << it << "  ";
    // cout << endl;

    dist[1] = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (auto it : edges)
        {
            auto [u, v, w] = it;

            if (visFromSource[u] && visFromDest[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                flag = 1;
            }
        }

        if(!flag)
            break;
    }

    if(flag) 
        cout << -1 << endl;
    else 
        cout << -dist[n] << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    // int t;
    // cin >> t;

    // while (t--)
    solve();

    return 0;
}