#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    int u, v;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> maxIn(n + 1), maxOut(n + 1);

    function<int(int, int)> InDfs = [&](int src, int par) {
        int& result = maxIn[src];

        for(auto child: g[src]) {
            if(child != par) {
                result = max(result, InDfs(child, src));
            }
        }
        result += 1;

        return result;
    };

    function<void(int, int)> OutDfs = [&](int src, int par) {
        int first = 0, second = 0;
        for(auto child: g[src]) {
            if(child != par) {
                if(maxIn[child] > first) {
                    second = first;
                    first = maxIn[child];
                } else if(maxIn[child] > second)
                    second = maxIn[child];
            }
        }

        for(auto child: g[src]) {
            if(child != par) {
                int curr = maxIn[child];

                int val = first > curr ? first : second;

                maxOut[child] = max(val, maxOut[src]) + 1;
                OutDfs(child, src);
            }
        }
    };

    InDfs(1, -1);
    OutDfs(1, -1);

    for(int i = 1; i <= n; i++) {
        cout << max(maxIn[i], maxOut[i] + 1) - 1 << " ";
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