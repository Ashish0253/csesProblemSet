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
    
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX), numbers(n + 1);
    numbers[n] = 1;
    dp[n] = 0;
    for(int i = n; i > 0; i--) {

        if(numbers[i] == 0) continue;

        int m = i;
        while(m != 0) {

            int unitDigit = m % 10;
            m = m / 10;

            if(unitDigit == 0) continue;
            
            if(dp[i - unitDigit] == INT_MAX) dp[i - unitDigit] = dp[i] + 1;
            else dp[i - unitDigit] = min(dp[i - unitDigit], dp[i] + 1);

            numbers[i - unitDigit] = 1;
        }
    } 

    // for(int i = 0; i <= n; i++) cout << dp[i] << " ";
    cout << dp[0];
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