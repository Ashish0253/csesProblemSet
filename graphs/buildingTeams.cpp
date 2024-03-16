#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<vector<int>> adj(N);
vector<int> vis(N);

bool flag = false;

void dfs(int node, int team)
{

    vis[node] = team;
    // deb(node);
    // deb(team);

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(it, team + 1);
        }

        if((vis[it]&1) == (team&1)) {
            flag = true;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++)
    {

        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, 1);
        }
    }

    if(flag) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] & 1)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 2 << " ";
        }

        // cout << vis[i] << " ";
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;

    // while (t--)
    solve();

    return 0;
}