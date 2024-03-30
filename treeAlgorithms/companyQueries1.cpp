#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<vector<int>> adj(N + 5);
int up[N + 5][20];

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

    for (int child : adj[src])
    {
        if (child != parent)
            binaryLifting(child, src);
    }
}

int ansQuery(int node, int jumpReq)
{
    if (node == -1 || jumpReq == 0)
        return node;

    for (int i = 19; i >= 0; i--)
    {
        if (jumpReq >= (1 << i))
        {
            return ansQuery(up[node][i], jumpReq - (1 << i));
        }
    }

    return -1;
}

void solve()
{

    int n, q;
    cin >> n >> q;

    int x;
    for (int i = 2; i < n + 1; i++)
    {

        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    binaryLifting(1, -1);

    int node, level;
    while (q--)
    {
        cin >> node >> level;

        cout << ansQuery(node, level) << endl;
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