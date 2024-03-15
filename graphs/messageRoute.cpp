#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<vector<int>> adj(N);
vector<int> vis(N, INT_MAX);
vector<int> par(N);

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

    queue<pair<int, int>> pq;
    vis[1] = 1;
    par[1] = 0;
    pq.push({1, 1});

    while(!pq.empty()) {

        int curr = pq.front().first;
        int step = pq.front().second;
        pq.pop();

        // deb(curr);

        for(auto it: adj[curr]) {
            // deb(it);

            if(vis[it] > step + 1) {

                // deb(it);
                vis[it] = step + 1;
                par[it] = curr;

                pq.push({it, step + 1});
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << vis[i] << " ";
    // }
    // cout << endl;

    if(vis[n] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int val = n;
    vector<int> ans;
    ans.push_back(val);

    while(val != 1) {

        ans.push_back(par[val]);
        val = par[val];
    }

    cout << vis[n] << endl;
    reverse(ans.begin(), ans.end());
    for(auto it: ans) {
        cout << it << " ";
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
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;

    // while (t--)
        solve();

    return 0;
}