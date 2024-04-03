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

    vector<vector<int>> adj(n + 1);
    vector<int> subordinates(n + 1);
    int x;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;

        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    function<void(int, int)> dfs = [&](int src, int parent)
    {
        for (auto child : adj[src]) {
            if(child != parent) {
                dfs(child, src);
                subordinates[src] += subordinates[child] + 1;
            }
        }
    };

    dfs(1, -1);

    for(int i = 1; i <= n; i++) {
        cout << subordinates[i] << " ";
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

    // int t;
    // cin >> t;

    // while (t--)
    solve();

    return 0;
}