#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

vector<vector<int>> adj;
vector<int> in, out, path;

void dfs(int node) {

    while(!adj[node].empty()) {
        int child = adj[node].back();
        adj[node].pop_back();

        dfs(child);
    }

    path.push_back(node);
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>> (n);
    in = vector<int> (n);
    out = vector<int> (n);

    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;

        adj[x].push_back(y);
        out[x]++; 
        in[y]++;
    }

    bool flag = true;
    for(int i = 1; i < n - 1; i++) {
        if(in[i] != out[i])
            flag = false;
    }
    

    if(out[0] != in[0] + 1 || in[n - 1] != out[n - 1] + 1 || !flag) {
        cout << "IMPOSSIBLE";
        return;
    }

    dfs(0);

    reverse(path.begin(), path.end());
    if(int(path.size()) != m + 1) {
        cout << "IMPOSSIBLE";
    } else {
        for(auto node: path) 
            cout << node + 1 << " ";
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