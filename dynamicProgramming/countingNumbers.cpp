#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

vector<int> num;
ll dp[20][12][2][2];

ll calculate(int pos, int prev, int tight, int nonZero) {

    if(pos == int(num.size())) {
        if(nonZero == 1 || (prev == 1 && nonZero == 0))
            return 1;
        return 0;
    }

    if(dp[pos][prev][tight][nonZero] != -1) 
        return dp[pos][prev][tight][nonZero];
    
    ll limit, res = 0;

    if(tight == 0)
        limit = num[pos] + 1;
    else 
        limit = 10;
    
    for(int digit = 1; digit <= limit; digit++) {

        int newTight = tight;
        int newNonZero = nonZero;

        if(tight == 0 && digit < limit)
            newTight = 1;
        
        if(nonZero == 0 && digit > 1)
            newNonZero = 1;
        
        if(digit != prev || (newNonZero == 0 && digit == 1)) {

            res += calculate(pos + 1, digit, newTight, newNonZero);
        }
    }

    return dp[pos][prev][tight][nonZero] = res;
}

ll solveFor(ll n) {

    if(n == 0)
        return 1;
    if(n < 0)
        return 0;

    num.clear();
    while(n != 0) {
        num.push_back(n % 10);

        n /= 10;
    }

    // for(auto it: num)
    //     cout << it << " ";
    // cout << endl;

    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));

    return calculate(0, 0, 0, 0);
}

void solve() {
    ll a, b;
    cin >> a >> b;

    ll res = solveFor(b);
    // deb(res);

    res -= solveFor(a - 1);

    cout << res << endl; 
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