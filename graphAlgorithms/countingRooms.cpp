#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl

const int MOD = 1e9 + 7;
const int mod = 998244353;

void dfs(vector<string> &vec, int i, int j) {

    int n = vec.size(), m = vec[0].size();

    if(vec[i][j] == '#') 
        return;
    
    vec[i][j] = '#';

    for(int k = -1; k <= 1; k += 2) {

        if(i + k >= 0 && i + k < n) 
            dfs(vec, i + k, j);
        if(j + k >= 0 && j + k < m) 
            dfs(vec, i, j + k);
    }
}

void solve()
{   
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(vec[i][j] == '.') {
                ans++;
                dfs(vec, i, j);
            }
        }
    }

    cout << ans << endl;
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
    // {
        solve();
    // }

    return 0;
}