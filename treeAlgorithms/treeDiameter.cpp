#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    
    vector<int> adj[n + 1];
    vector<vector<int>> maxHeight(n + 1, vector<int> (2));
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<int(int, int, int)> dfs = [&](int src, int parent, int lvl) {

        for(auto child: adj[src]) {
            if(child != parent) {
                int response = dfs(child, src, lvl + 1);

                if(response >= maxHeight[src][0]) {
                    maxHeight[src][1] = maxHeight[src][0];
                    maxHeight[src][0] = response;
                }
                else if(response > maxHeight[src][1]) {
                    maxHeight[src][1] = response;
                }
            }
        }

        return maxHeight[src][0] + 1;
    };

    dfs(1, -1, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, maxHeight[i][0] + maxHeight[i][1]);

        // cout << maxHeight[i][0] << " " << maxHeight[i][1] << endl;
    }

    cout << ans << endl;

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