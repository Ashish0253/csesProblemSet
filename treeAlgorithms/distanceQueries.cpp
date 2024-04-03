#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> adj[N];
int lvl[N];
int up[N][20];


void dfs(int src, int parent, int level)
{
    lvl[src] = level;
    for (auto child : adj[src])
    {
        if (child != parent)
            dfs(child, src, level + 1);
    }
}

void binaryLifting(int src, int parent)
{
    up[src][0] = parent;
    for (int i = 1; i < 20; i++)
    {
        if (up[src][i - 1] != -1)
            up[src][i] = up[up[src][i - 1]][i - 1];
        else
            up[src][i] = -1;
    }

    for (auto child : adj[src])
    {
        if (child != parent)
            binaryLifting(child, src);
    }
}

int liftNode(int node, int jumpReq)
{
    for (int i = 19; i >= 0; i--)
    {
        if (jumpReq == 0 || node == -1)
            break;

        if (jumpReq >= (1 << i))
        {
            jumpReq -= (1 << i);
            node = up[node][i];
        }
    }

    return node;
}

int lca(int u, int v) {

    if (lvl[u] < lvl[v])
        swap(u, v);

    u = liftNode(u, lvl[u] - lvl[v]);

    if (u == v)
        return u;

    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return liftNode(u, 1);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // for(int i = 1; i <= n; i++) 
    //     cout << lvl[i] << " ";
    // cout << endl;

    dfs(1, -1, 0);
    binaryLifting(1, -1);

    while (q--)
    {
        cin >> x >> y;

        int LCA = lca(x, y);
        cout << lvl[x] + lvl[y] - 2 * lvl[LCA] << endl;
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