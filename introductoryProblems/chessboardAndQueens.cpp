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

bool isValid(vector<string> &chessBoard, int row, int col) {

    // ROW AND COL CHECK
    fo(i, 0, 8) {
        // ROW
        if(i != col && chessBoard[row][i] == 'Q') return false;
        // COL
        if(i != row && chessBoard[i][col] == 'Q') return false;
    }

    // DIAGONAL CHECK
    int i = row, j = col;
    while(i >= 0 && j >= 0) {
        
        if(chessBoard[i--][j--] == 'Q') return false;
    }

    i = row, j = col;
    while(i < 8 && j < 8) {
        
        if(chessBoard[i++][j++] == 'Q') return false;
    }

    i = row, j = col;
    while(i >= 0 && j < 8) {

        if(chessBoard[i--][j++] == 'Q') return false;

    }

    i = row, j = col;
    while(i < 8 && j >= 0) {

        if(chessBoard[i++][j--] == 'Q') return false;

    }

    return true;
}

int solve(vector<string> &chessBoard, int row, int &cnt) {
    // BASE CASE
    if(row >= 8) {
        cnt++;
        return 0;
    }

    fo(col, 0, 8) {

        if(chessBoard[row][col] != '*' && isValid(chessBoard, row, col)) {
            chessBoard[row][col] = 'Q';
            solve(chessBoard, row+1, cnt);
            chessBoard[row][col] = '.';
        }
    }

    return 0;
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

    vector<string> chessBoard;
    string str;
    fo(i, 0, 8) {
        cin>>str;

        chessBoard.pb(str);
    } 

    int cnt = 0;
    solve(chessBoard, 0, cnt);

    cout<<cnt<<endl;

    return 0;
}