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
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct item
{
    int left, right, idx;
};

void solve()
{

    int n;
    cin >> n;

    vector<item> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].left >> vec[i].right;

        vec[i].idx = i;
    }

    sort(vec.begin(), vec.end(), [](item a, item b)
         {

        if(a.left < b.left)
            return true;
        
        if(a.left == b.left && a.right > b.right) 
            return true;
        
        return false; });

    // for(int i = 0; i < n; i++) {
    //     cout << vec[i].left << " " << vec[i].right << endl;
    // }

    ordered_set<pair<int, int>> st;

    vector<int> isContains(n), isContained(n);
    for (int i = 0; i < n; i++)
    {
        st.insert({vec[i].right, -i});

        isContained[vec[i].idx] = st.size() - st.order_of_key({vec[i].right, -i}) - 1;
    }

    st.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        st.insert({vec[i].right, -i});

        isContains[vec[i].idx] = st.order_of_key({vec[i].right, -i});
    }

    for (int i = 0; i < n; i++)
        cout << isContains[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << isContained[i] << " ";
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