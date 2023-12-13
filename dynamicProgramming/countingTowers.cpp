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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    int n = 1e6;
    vector<vector<int>> dp(n, vector<int> (2, 0));

    dp[0][0] = 1;
    dp[0][1] = 1;

    for(int i = 1; i < n; i++) {

        long long op1 = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        long long op2 = (dp[i - 1][0]) % mod;
        long long op3 = (2 * dp[i - 1][0]) % mod;
        long long op4 = (dp[i - 1][1]) % mod;

        dp[i][0] = (op1 + op2 + op3) % mod;
        dp[i][1] = (op1 + op4) % mod;
    }

    while (t--)
    {
        int m;
        cin >> m;

        cout << (dp[m - 1][0] + dp[m - 1][1]) % mod << endl;
    }
    return 0;
}