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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n; cin>>n;

    ll sum = n*(n+1)/2;
    if(sum&1) {
        cout<<"NO"<<endl;
    }
    else {
        vi first, second;
        cout<<"YES"<<endl;
        sum /= 2;

        for(int i=n; i>0; i--) {
            if(i <= sum) {
                sum -= i;
                first.pb(i);
            }
            else {
                second.pb(i);
            }
        }

        cout<<first.size()<<endl;
        for(auto it: first) cout<<it<<" ";
        cout<<endl;
        cout<<second.size()<<endl;
        for(auto it: second) cout<<it<<" ";
        cout<<endl;

    }

    
    return 0;
}