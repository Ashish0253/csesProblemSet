#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, a, n) for (int i = a; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << " = " << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define sortrev(x) sort(rev(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vll> vvl;

// vector<vector<bool>> grid(7, vector<bool> (7, 0));
bool grid[7][7];  // DECLARATION OF ARRAY IS FASTER THAN VECTORS
int cnt = 0;
string str;
 
bool isValid(int row, int col) {
    return row >= 0 && row < 7 && col >= 0 && col < 7;
}
 
void solve(int row, int col, int i) {
    // BASE CASE
    if(i == 48 || (row == 6 && col == 0)) {
        cnt += (i == 48 && (row == 6 && col == 0));
        return;
    }
 
    // bool hitwall = ((col >= 1 && col <= 5 && !grid[row][col+1] && !grid[row][col-1]) && 
    //     ((row == 0 && grid[row+1][col]) || (row == 6 && grid[row-1][col])))  
    //                     or
    //     ((row >= 1 && row <= 5 && !grid[row+1][col] && !grid[row-1][col]) && 
    //     ((col == 0 && grid[row][col+1]) || (col == 6 && grid[row][col-1]))); 
    
 
    // bool isSquaresLeft =  (row >= 1 && row <= 5 && col >= 1 && col <= 5 && grid[row+1][col] &&
    //                     grid[row-1][col] && !grid[row][col-1] && !grid[row][col+1]) 
    //                         or
    //                     (row >= 1 && row <= 5 && col >= 1 && col <= 5 && grid[row][col+1] &&
    //                     grid[row][col-1] && !grid[row-1][col] && !grid[row+1][col]);
 
    // if(hitwall || isSquaresLeft) return;  
    


    // IT IS THE SAME THING AS WRITTEN ABOVE BUT IN A MUCH MORE CONCISE WAY
    if((!isValid(row+1, col) || grid[row+1][col]) && (!isValid(row-1, col) || grid[row-1][col]))   
        if(isValid(row, col-1) && !grid[row][col-1] && isValid(row, col+1) && !grid[row][col+1])
            return;
 
    if((!isValid(row, col+1) || grid[row][col+1]) && (!isValid(row, col-1) || grid[row][col-1]))   
        if(isValid(row-1, col) && !grid[row-1][col] && isValid(row+1, col) && !grid[row+1][col])
            return;
 
 
    grid[row][col] = 1;
 
    // DOWN - 'D'
    if(str[i] == 'D' || str[i] == '?')
        if(isValid(row+1, col) && !grid[row+1][col]) 
            solve(row+1, col, i+1);
 
    // UP - 'U'
    if(str[i] == 'U' || str[i] == '?')
        if(isValid(row-1, col) && !grid[row-1][col]) 
            solve(row-1, col, i+1);
        
    // RIGHT - 'R'
    if(str[i] == 'R' || str[i] == '?')
        if(isValid(row, col+1) && !grid[row][col+1]) 
            solve(row, col+1, i+1);
 
    // LEFT - 'L'
    if(str[i] == 'L' || str[i] == '?')
        if(isValid(row, col-1) && !grid[row][col-1]) 
            solve(row, col-1, i+1);
 
    grid[row][col] = 0;
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
    
    cin>>str;
    
    solve(0, 0, 0);
 
    cout<<cnt<<endl;
 
    return 0;
}