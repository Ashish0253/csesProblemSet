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
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve() {
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<vector<long long>> dp(n, vector<long long> (m + 2, 0));
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    if(a[0] == 0) 
        for(int i = 1; i <= m; i++) dp[0][i] = 1;
    else 
        dp[0][a[0]] = 1;

    for(int i = 1; i < n; i++) {

        if(a[i] != 0) {

            dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
        }
        else {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j <= m + 1; j++) {

    //         cout << dp[i][j] <<" ";
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = ( ans + dp[n-1][i] ) % MOD;
    } 

    cout << ans;

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