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

    vpii a(n + 1);
    fo(i, 0, n) {

        cin >> a[i].first;
        a[i].second = i; 
    }
    set<pii> left, right;
    fo(i, 0, k) left.insert(a[i]);

    int odd = 1 ? (k & 1) : 0;

    fo(i, k, n + 1) {

        // IF LEFT SET HAS MORE ELEMENT
        while(left.size() > right.size() + odd) {

            auto lastElement = *left.rbegin();
            right.insert(lastElement);
            left.erase(lastElement);
        }

        // IF LEFT SET HAS LESS ELEMENT
        while(left.size() < right.size() + odd) {

            auto firstElement = *right.begin();
            left.insert(firstElement);
            right.erase(firstElement);
        }

        // cout << "LEFT" << endl;
        // for(auto it : left) {
        //     cout << it.first << " " << it.second << endl;
        // }

        // cout << "RIGHT" << endl;
        // for(auto it : right) {
        //     cout << it.first << " " << it.second << endl;
        // }

        cout << left.rbegin()->first << " ";

        // ADDING CURRENT ELEMENT
        if(!left.empty() && a[i].first >= left.rbegin()->first) 
            right.insert(a[i]);
        else 
            left.insert(a[i]);

        // REMOVING THE FIRST ELEMENT
        if(left.find(a[i - k]) != left.end()) {
            left.erase(a[i - k]);
        }
        else right.erase(a[i - k]);
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