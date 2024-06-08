#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

vector<vector<int>> g;
vector<int> path;

void dfs(int node) {
    while(!g[node].empty()) {
        int child = g[node].back();
        g[node].pop_back();

        dfs(child);
    }

    path.emplace_back(node & 1);
}

void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << 10;
        return;
    }
    
    g = vector<vector<int>> (1 << (n - 1));

    for(int node = 0; node < (1 << (n - 1)); node++) {
        int edge = (node << 1) % (1 << (n - 1));

        g[node].emplace_back(edge);
        g[node].emplace_back(edge | 1);
    }

    dfs(0);

    for(int i = 0; i < n - 2; i++)
        path.emplace_back(0);

    for(auto it: path)
        cout << it;
    
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