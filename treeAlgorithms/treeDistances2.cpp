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

    vector<ll> totalIn(n + 1), totalOut(n + 1);
    vector<ll> childCnt(n + 1);
    
    function<ll(int, int)> InDfs = [&](int src, int par) {
        ll& result = totalIn[src];
        int cnt = 0;
        for(auto child: g[src]) {
            if(child != par) {
                cnt++;
                result += InDfs(child, src);
                childCnt[src] += childCnt[child];
            }
        }
        childCnt[src] += cnt;
        return result + childCnt[src] + 1;
    };

    function<void(int, int)> OutDfs = [&](int src, int par) {
        for(auto child: g[src]) {
            if(child != par) {
                // REMOVING THE CONTRIBUTION OF CHILD TO SRC
                totalOut[child] = totalIn[src] + totalOut[src] - (childCnt[child] + 1) - totalIn[child];
                // ADDING THE EXTRA TIME I HAVE TO TRAVEL FROM CHILD TO SRC
                totalOut[child] += childCnt[src] - childCnt[child];
                // ADDING THE OTHER CHILD OF SRC TO THE CHILD COUNT
                childCnt[child] += childCnt[src] - childCnt[child];

                OutDfs(child, src);
            }
        }
        
    };

    InDfs(1, -1);
    OutDfs(1, -1);

    // for(auto it: totalIn)
    //     cout << it << " ";
    // cout << endl;
    // for(auto it: childCnt)
    //     cout << it << " ";
    // cout << endl;
    // for(auto it: totalOut)
    //     cout << it << " ";
    // cout << endl;

    for(int i = 1; i <= n; i++)
        cout << totalIn[i] + totalOut[i] << " ";
    
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