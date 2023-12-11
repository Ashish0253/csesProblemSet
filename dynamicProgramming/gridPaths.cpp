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

void solve() {
    
    int n;
    cin >> n;

    vector<string> path(n);
    for(int i = 0; i < n; i++) cin >> path[i];

    if(path[0][0] == '*') {
        cout << 0;
        return;
    }
    
    vector<vector<int>> possiblePaths(n, vector<int> (n, 0));
    possiblePaths[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(path[i][j] == '*') continue;

            if(i + 1 < n && path[i + 1][j] != '*') 
                possiblePaths[i + 1][j] = (possiblePaths[i + 1][j] + possiblePaths[i][j]) % MOD;
            
            if(j + 1 < n && path[i][j + 1] != '*') 
                possiblePaths[i][j + 1] = (possiblePaths[i][j + 1] + possiblePaths[i][j]) % MOD;
        }
    }

    cout << possiblePaths[n - 1][n - 1];
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