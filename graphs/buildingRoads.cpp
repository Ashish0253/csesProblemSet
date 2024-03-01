#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

int cnt = 1;
vector<vector<int>> adj(N);
vector<int> vis(N);

void dfs(int node) {

    vis[node] = cnt;

    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            dfs(it);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            dfs(i);
            cnt++;
        }
    }

    int groups = cnt - 1;
    vector<int> nodes(groups + 1);
    for(int i = 1; i <= n; i++) {
        nodes[vis[i]] = i;
    }
    cout << groups - 1 << endl; 
    for(int i = 1; i < nodes.size() - 1; i++) {
        cout << nodes[i] << " " << nodes[i + 1] << endl;
    }
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