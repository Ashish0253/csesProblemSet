#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<vector<int>> adj(N);
vector<bool> vis(N);
bool flag = false;
vector<int> path, ans;

void dfs(int node, int parent)
{
    vis[node] = 1;

    path.push_back(node);

    for (auto it : adj[node])
    {
        if(it == parent) continue;

        if (!vis[it])
        {
            dfs(it, node);
        }
        else
        {
            if (path.size() > 2 && !flag)
            {
                flag = true;
                ans = path;
                ans.push_back(it);
                return;
            }
        }
    }

    path.pop_back();
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
        if (!vis[i])
        {
            dfs(i, -1);
        }
    }

    if(!flag) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int cnt = 1;
    for(int i = ans.size() - 2; i >= 0; i--) {

        cnt++;
        if(ans.back() == ans[i]) {
            break;
        }
    }

    cout << cnt << endl;
    while(cnt--) {
        cout << ans.back() << " ";
        ans.pop_back();
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