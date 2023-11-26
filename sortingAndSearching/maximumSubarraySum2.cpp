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
    
    int n, a, b;
    cin >> n >> a >> b;

    vpl vec(n + 1);
    fo(i, 1, n + 1) {
        cin >> vec[i].first;
        vec[i].first += vec[i-1].first;
        vec[i].second = i + 1;

        // cout << vec[i].first << " ";
    }

    set<pl> st;

    fo(i, a, b + 1) {
        st.insert(vec[i]);
        // deb(st.size());
    }

    ll preSum = 0;
    ll ans = LLONG_MIN;
    for(int i = 1; i + a <= n + 1; i++) {

        auto maxi = *st.rbegin();

        ans = max(ans, maxi.first - preSum);
        st.erase(vec[i + a - 1]);
        st.insert(vec[min(i + b, n)]);

        preSum = vec[i].first;
    } 

    cout << ans << endl;
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