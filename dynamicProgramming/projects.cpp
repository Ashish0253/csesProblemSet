#include <bits/stdc++.h>
using namespace std;

struct item {
    int endDay, startDay, price;
};

int findBest(vector<int> &endPts, int val) {

    auto it = lower_bound(endPts.begin(), endPts.end(), val);
    if(it == endPts.begin()) {
        return 0;
    }
    else {
        it--;
        return 1 + distance(endPts.begin(), it);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<item> vec(n + 1);
    for(int i = 1; i <= n; i++) {

        long long start, end, price;
        cin >> start >> end >> price;

        vec[i].endDay = end;
        vec[i].startDay = start;
        vec[i].price = price;
    }

    sort(vec.begin(), vec.end(), [](item a, item b) {
        return a.endDay < b.endDay;
    });

    vector<long long> dp(n + 1);
    
    vector<int> endPts;
    for(int i = 1; i <= n; i++) {
        endPts.push_back(vec[i].endDay);
    }

    for(int i = 1; i <= n; i++) {

        long long op1 = dp[i - 1];
        long long op2 = vec[i].price;

        int idx = findBest(endPts, vec[i].startDay);

        op2 += dp[idx];
        dp[i] = max(op1, op2);
    }

    cout << dp[n] << endl;
    
}