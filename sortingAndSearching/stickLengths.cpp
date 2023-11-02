#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, a, n) for(int i = a; i < n; ++i)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << " = " << x << endl
#define pb push_back
// #define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define sortrev(x) sort(rev(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define mod 998244353

#define inp(a)         \
    for (auto &it : a) \
    cin >> it
#define outp(a)        \
    for (auto &it : a) \
    cout << it << " "; \
    cout << endl
#define nl endl
#define nope cout<<"NO"<<endl
#define yup cout<<"YES"<<endl

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;

void solve()
{
    ll n;
    cin >> n;

    vl a(n);
    inp(a);

    sortall(a);

    ll mid = n / 2;

    ll ans = 0;
    fo(i, 0, n) {

        ans += abs(a[i] - a[mid]);
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
        solve();

    return 0;
}