#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (ll i = a; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve() {
    
    int a, b;
    cin >> a >> b;

    int n = min(a, b);
    int m = max(a, b);
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    for(int i = 1; i <= m; i++) 
        dp[1][i] = i - 1;
    for(int i = 1; i <= n; i++) 
        dp[i][1] = i - 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {

            if(i == j) continue;

            int ans = INT_MAX;

            for(int k = 1; k < i; k++) {
                ans = min(ans, dp[i - k][j] + dp[k][j]);
            }
            for(int k = 1; k < j; k++) {
                ans = min(ans, dp[i][j - k] + dp[i][k]);
            }

            dp[i][j] = 1 + ans;
        }
    } 

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][m];
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