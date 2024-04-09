#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;
const ll INF = LLONG_MAX;

typedef tuple<ll, int, int> node;
priority_queue<node, vector<node>, greater<node>> pq;

struct item
{
    int dest;
    ll fare;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<item> adj[n + 1];
    int u, v, cost;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> cost;

        adj[u].push_back({v, cost});
    }

    // DJIKSTRA SHORTEST PATH CAN WORK
    ll distance[2][n + 1];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            distance[i][j] = INF;
        }
    }

    distance[1][1] = distance[0][1] = 0;
    pq.push({0, 1, 1});

    while (!pq.empty())
    {
        auto [dist, src, coupon] = pq.top();
        pq.pop();

        if(distance[!coupon][src] < dist) 
            continue;

        for (auto edge : adj[src])
        {
            auto [child, cost] = edge;

            if (coupon)
            {
                if (distance[0][child] > dist + cost)
                {
                    distance[0][child] = dist + cost;
                    pq.push({dist + cost, child, 1});
                }
                if (distance[1][child] > dist + cost / 2)
                {
                    distance[1][child] = dist + cost / 2;
                    pq.push({dist + cost / 2, child, 0});
                }
            }
            else
            {
                if (distance[1][child] > dist + cost)
                {
                    distance[1][child] = dist + cost;
                    pq.push({dist + cost, child, 0});
                }
            }
        }
    }

    cout << distance[1][n] << endl;
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