#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MODINV2 500000004 // HOW TO FIND THIS ??

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);

    long long n;
    cin >> n;

    long long m = n * (n + 1) / 2;
    if (m & 1)
    {
        cout << 0 << endl;
        return 0;
    }
    m /= 2;

    vector<long long> dp(m + 1);
    dp[0] = 1;

    for (long long val = 1; val <= n; val++)
    {
        for (long long sum = m; sum >= val; sum--)
        {
            dp[sum] = (dp[sum] + dp[sum - val]) % MOD;
        }

        // for(int j = 0; j <= m; j++) {
        //     cout << dp[j] << " ";
        // }
        // cout << endl;
    }

    cout << (dp[m] * MODINV2) % MOD << endl;

    return 0;
}