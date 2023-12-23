#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);

    int n, limit;
    cin >> n >> limit;

    vector<int> weights(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<pair<int, int>> dp(1 << n, {1e9, 1e9});
    dp[0] = {1, 0};
    
    for(int mask = 1; mask < (1 << n); mask++) {
        for(int bit = 0; bit < n; bit++) {

            if((1 << bit) & mask) {
                int spaceTaken = dp[mask ^ (1 << bit)].second;

                if(spaceTaken + weights[bit] <= limit) {
                    dp[mask] = min(dp[mask], {dp[mask ^ (1 << bit)].first, spaceTaken + weights[bit]});
                }
                else {
                    dp[mask] = min(dp[mask], {dp[mask ^ (1 << bit)].first + 1, weights[bit]});
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first;
}