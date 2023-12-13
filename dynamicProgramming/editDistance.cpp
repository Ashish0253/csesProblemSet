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

vvi dp(5005, vi (5005, -1));

int memo(int i, int j, string& s, string& p) {

    if(i == (int)s.length() || j == (int)p.length()) {
        return max(s.length() - i, p.length() - j);
    }

    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = 0;
    
    if(s[i] != p[j]) {
        int op1 = 1 + memo(i, j + 1, s, p); // INSERT
        int op2 = 1 + memo(i + 1, j + 1, s, p); // REPLACE
        int op3 = 1 + memo(i + 1, j, s, p); // REMOVE

        ans = min(op1, min(op2, op3));
    } 
    else {
        ans = memo(i + 1, j + 1, s, p);
    }

    return dp[i][j] = ans;
}

void solve() {
    
    string s, p;
    cin >> s >> p;

    // MEMOIZATION
    // cout << memo(0, 0, s, p);

    // TABULATION
    int n = p.size(), m = s.size();
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[0][i] = i;
    for(int i = 1; i <= m; i++) dp[i][0] = i;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {

            if(s[i - 1] == p[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else {

                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    cout << dp[m][n];

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