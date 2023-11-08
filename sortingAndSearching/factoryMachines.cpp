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

void solve() {
    
    ll n, t;
    cin >> n >> t;

    vl timeTaken(n);
    inp(timeTaken);

    ll low = 1, high = 1e18;
    ll minTime = 1e18;
    while(low <= high) {

        ll mid = low + (high - low) / 2;
        // deb(mid);

        ll productsPrepared = 0;
        fo(i, 0, n) {

            productsPrepared += mid / timeTaken[i];
            if(productsPrepared >= t) break; 
        }

        // deb(productsPrepared);

        if(productsPrepared >= t)  {
            minTime = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << minTime << endl;
    
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