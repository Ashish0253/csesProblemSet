#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 5;

struct item
{
    int node;
    ll dist;
};

vector<vector<item>> adj(N);
vector<bool> vis(N);
vector<ll> dist(N, LLONG_MAX);

void solve()
{
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {

        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    set<pair<ll, int>> st;
    st.insert({0, 1});
    dist[1] = 0;

    while(!st.empty())
    {
        auto top = *st.begin();
        st.erase(top);

        if(vis[top.second])
            continue;
        vis[top.second] = 1;

        for(auto it: adj[top.second]) {

            if(dist[it.node] > top.first + it.dist) {
                dist[it.node] = top.first + it.dist;

                st.insert({top.first + it.dist, it.node});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
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