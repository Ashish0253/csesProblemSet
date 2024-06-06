#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 500 + 5;
const ll INF = 1e12 + 5;

vector<vector<ll>> adj(N, vector<ll>(N, INF));

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        if(adj[a][b] == INF) {
            adj[a][b] = c;
            adj[b][a] = c;
        } else {
            adj[a][b] = min(adj[a][b], c);
            adj[b][a] = min(adj[b][a], c);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }

    // FLOYD WARSHALL'S ALGORITHM
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {

                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }

    // for (int j = 1; j <= n; j++)
    // {
    //     for (int k = 1; k <= n; k++)
    //     {
    //         cout << adj[j][k] << " ";
    //     }
    //     cout << endl;
    // }

    int x, y;
    while (q--)
    {

        cin >> x >> y;

        if (adj[x][y] == INF)
            cout << -1 << endl;
        else
            cout << adj[x][y] << endl;
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