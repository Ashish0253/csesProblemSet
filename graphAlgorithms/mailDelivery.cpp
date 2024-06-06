#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

vector<vector<pair<int, int>>> adj;
vector<int> degree, path;
vector<bool> seen;

void dfs(int node)
{

    // deb(node);

    while (!adj[node].empty())
    {
        auto [child, idx] = adj[node].back();
        adj[node].pop_back();

        if (seen[idx])
            continue;

        seen[idx] = true;
        dfs(child);
    }

    path.push_back(node);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    adj = vector<vector<pair<int, int>>>(n);
    degree = vector<int>(n);
    seen = vector<bool>(m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        adj[x].push_back({y, i});
        adj[y].push_back({x, i});

        degree[x]++;
        degree[y]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (degree[i] & 1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    dfs(0);

    if (int(path.size()) != m + 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
        for (auto node : path)
            cout << node + 1 << " ";
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