#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(auto &it: a)
        cin >> it;

    vector<int> prefXor(n + 1);
    prefXor[0] = 0;
    for(int i = 1; i < n + 1; i++) 
        prefXor[i] = prefXor[i - 1] ^ a[i - 1];
    
    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << (prefXor[l - 1] ^ prefXor[r]) << endl;
    }

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