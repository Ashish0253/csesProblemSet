#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];
    vector<int> edgeCnt(n + 1);
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    function<int(int, int)> dfs = [&](int src, int parent)
    {
        for (auto child : adj[src])
        {
            if (child != parent)
            {   
                int response = dfs(child, src);
                if(response && edgeCnt[src] == 0) {
                    edgeCnt[src] = 1;
                    edgeCnt[child] = 1;
                    cnt++;
                }
            }
        }

        // deb(src);
        // deb(edgeCnt[src]);
        return 1 - edgeCnt[src];
    };

    dfs(1, -1);

    cout << cnt << endl;

    
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