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

    vi a(n + 1);
    fo(i, 0, n) cin >> a[i];

    set<pii> leftSet, rightSet;
    ll leftSum = 0, rightSum = 0;

    int odd = k % 2;
    fo(i, 0, k) {

        leftSet.insert({a[i], i});
        leftSum += a[i];
    }

    fo(i, k, n + 1) {

        while(leftSet.size() > rightSet.size() + odd) {

            pii last = *leftSet.rbegin();
            leftSet.erase(last);
            leftSum -= last.first;
            rightSum += last.first;
            rightSet.insert(last);
        }

        while(leftSet.size() < rightSet.size() + odd) {

            pii first = *rightSet.begin();
            rightSet.erase(first);
            rightSum -= first.first;
            leftSum += first.first;
            leftSet.insert(first);
        }

        // cout << "LEFT" << endl;
        // for(auto it : leftSet) {
        //     cout << it.first << " " << it.second << endl;
        // }

        // cout << "RIGHT" << endl;
        // for(auto it : rightSet) {
        //     cout << it.first << " " << it.second << endl;
        // }

        // deb(leftSum);
        // deb(rightSum);

        int median = leftSet.rbegin()->first;
        cout << ( leftSet.size() * median ) - leftSum + rightSum - (rightSet.size() * median) << " ";

        // INSERTING THE NEW ELEMENT
        if(!leftSet.empty() && leftSet.rbegin()->first > a[i]) {
            leftSum += a[i];
            leftSet.insert({a[i], i});
        }
        else {
            rightSum += a[i];
            rightSet.insert({a[i], i});
        }

        // REMOVING THE i - k TH ELEMENT
        if(leftSet.count({a[i - k], i - k})) { 
            leftSum -= a[i - k];
            leftSet.erase({a[i - k], i - k});
        }
        else { 
            rightSum -= a[i - k];
            rightSet.erase({a[i - k], i - k});
        } 
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