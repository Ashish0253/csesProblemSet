#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

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

        if(a.left < b.left) {
            return 1;
        } 

        if(a.left == b.left && a.right > b.right) {
            return 1;
        }

        return 0; });

    // for (int i = 0; i < n; i++)
    // {
    //     cout << vec[i].left << " " << vec[i].right << endl;
    // }

    vector<int> iscontains(n);
    vector<int> iscontained(n);
    int limit = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].right <= limit)
        {
            iscontained[vec[i].idx] = 1;
        }

        limit = max(vec[i].right, limit);
    }

    limit = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vec[i].right >= limit)
        {
            iscontains[vec[i].idx] = 1;
        }

        limit = min(vec[i].right, limit);
    }

    for (int i = 0; i < n; i++)
        cout << iscontains[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << iscontained[i] << " ";
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