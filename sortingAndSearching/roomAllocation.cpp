#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (int i = a; i < n; i++)
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define Time first
#define Type second.first 
#define Idx second.second

void solve() {
    
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> queries(2 * n);
    set<int> st;
    fo(i, 0, n) {

        st.insert(i + 1);

        int entry, exit;
        cin >> entry >> exit;

        queries[2*i] = {entry, {0, i}};
        queries[2*i + 1] = {exit, {1, i}};
    }

    sortall(queries);

    vi ans(n);
    for(auto it: queries) {

        // cout << it.Time << " " << it.Type << " " << it.Idx << endl; 

        if(it.Type == 0) {
            ans[it.Idx] = *st.begin();
            st.erase(st.begin());
        }
        else {
            st.insert(ans[it.Idx]);
        }
    }

    cout << *max_element(all(ans)) << endl;
    outp(ans);


    // APPROACH USING MULTIMAP

    // vector<pair<pair<int, int>, int>> a(n);
    // fo(i, 0, n) {

    //     a[i].second = i;
    //     cin >> a[i].first.first >> a[i].first.second;
    // }

    // sortall(a);
    // multimap<int, int> mp;

    // int roomCnt = 1;
    // vi roomsAlloted(n);
    // int entry, exit;
    // fo(i, 0, n) {
        
    //     int idx = a[i].second;
    //     entry = a[i].first.first;
    //     exit = a[i].first.second;

    //     auto it = mp.upper_bound(-entry);
    //     if( it == mp.end()) {

    //         roomsAlloted[idx] = roomCnt;
    //         mp.insert({-exit, roomCnt});
    //         roomCnt++;
    //     }
    //     else {

    //         int room = it->second;
    //         roomsAlloted[idx] = room;

    //         mp.erase(it);

    //         mp.insert({-exit, room});
    //     }
    // }

    // cout << *max_element(all(roomsAlloted)) << endl;
    // outp(roomsAlloted);
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