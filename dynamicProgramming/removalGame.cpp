#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp(5001, vector<long long> (5001, -1));

long long solve(int i, int j, vector<long long> &points) {
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // TAKE THE FIRST ONE
    long long ans1 = points[i] - (solve(i + 1, j, points));
    // TAKE THE SECOND ONE 
    long long ans2 = points[j] - (solve(i, j - 1, points));

    return dp[i][j] = max(ans1, ans2);
}

int main() 
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    

    vector<long long> points(n);
    for(auto &it: points) {
        cin >> it;
    }

    // MEMOIZATION
    // long long diff = solve(0, n - 1, points) ;

    // TABULATION
    for(int i = 0; i < n; i++) {
        dp[i][i] = points[i];
    }

    for(int left = n - 1; left >= 0; left--) {
        for(int right = left + 1; right < n; right++) {

            long long chooseLeft = points[left] - dp[left + 1][right];
            long long chooseRight = points[right] - dp[left][right - 1];

            dp[left][right] = max(chooseLeft, chooseRight);
        }
    }


    cout << (accumulate(points.begin(), points.end(), 0LL) + dp[0][n - 1]) / 2 << endl;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) 
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

}