#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    vector<int> len;
    len.push_back(vec[0]);
    for(int i = 1; i < n; i++) {

        if(vec[i] > len.back()) {
            len.push_back(vec[i]);
        }
        else {
            auto idx = lower_bound(len.begin(), len.end(), vec[i]) - len.begin();
            len[idx] = vec[i];
        }
    }

    cout << len.size() << endl;
}