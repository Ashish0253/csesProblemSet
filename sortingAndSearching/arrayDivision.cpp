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
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    fo(i, 0, n) cin >> a[i];

    ll low = *max_element(all(a)), high = 1e18;
    ll ans = 1e18;
    while(low <= high) {

        ll mid = low + (high - low) / 2;

        // COUNT FOR SUBARRAYS SUM LESS THAN OR EQUAL TO MID
        ll sum = 0;
        int j = 0, cnt = 1;
        while(j < n) {

            sum += a[j];

            if(sum > mid) {
                sum = a[j];

                cnt++;
            }

            j++;
        }  

        // deb(cnt); 
        // deb(mid);

        if(cnt <= k) {

            high = mid - 1;
            ans = min(ans, mid);
        }
        else {
            low = mid + 1;
        }
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