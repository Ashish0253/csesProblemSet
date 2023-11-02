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
    
    int n, m;
    cin >> n >> m;

    vi arr(n + 1), pos(n + 2);
    fo(i, 1, n + 1) {
        cin >> arr[i];

        pos[arr[i]] = i;
    }

    pos[n + 1] = n + 1;

    int ans = 1, prev = pos[1];
    fo(i, 2, n + 1) {

        if(prev > pos[i]) ans++;

        prev = pos[i];
    }

    while(m--) {
        int a, b;
        cin >> a >> b;

        set<pii> st;

        st.insert({arr[a] - 1, arr[a]});
        st.insert({arr[a], arr[a] + 1});
        st.insert({arr[b] - 1, arr[b]});
        st.insert({arr[b], arr[b] + 1});

        for(auto it: st) {

            int x = it.first, y = it.second;

            if(pos[x] > pos[y]) ans--;
        }

        swap(arr[a], arr[b]);
        pos[arr[a]] = a;
        pos[arr[b]] = b;

        for(auto it: st) {

            int x = it.first, y = it.second;

            if(pos[x] > pos[y]) ans++;
        }

        cout << ans << endl;
    }
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