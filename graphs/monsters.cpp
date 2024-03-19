#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl
#define ll long long

const int MOD = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y, int n, int m) {

    if(x >= 0 && x < n && y >= 0 && y < m)
        return 1;
    else 
        return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    queue<pair<int, pair<int, int>>> monsterQ, playerQ;
    vector<vector<int>> monsterMap(n, vector<int> (m, INT_MAX));
    vector<vector<int>> playerMap(n, vector<int> (m, INT_MAX));
    for(int i = 0; i < n; i++) {
        cin >> vec[i];

        for(int j = 0; j < m; j++) {

            if(vec[i][j] == 'M') {
                monsterQ.push({0, {i, j}});
                monsterMap[i][j] = 0;
            }
            else if(vec[i][j] == 'A') {
                playerQ.push({0, {i, j}});
                playerMap[i][j] = 0;

                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    cout << "YES" << endl;
                    cout << 0 << endl;
                    return;
                }

            }
        }
    }

    // FINDING THE STEPS TO REACH THE BOUNDARY POINT BY THE MONSTERS
    while(!monsterQ.empty()) {

        int steps = monsterQ.front().first;
        int x = monsterQ.front().second.first;        
        int y = monsterQ.front().second.second;
        monsterQ.pop();

        for(int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isValid(nx, ny, n, m) && vec[nx][ny] != '#' && monsterMap[nx][ny] > steps + 1) {
                monsterQ.push({steps + 1, {nx, ny}});
                monsterMap[nx][ny] = steps + 1;
            }
        }
    }

    // FINDING THE STEPS TO REACH THE BOUNDARY POINT BY THE PLAYER
    while(!playerQ.empty()) {

        int steps = playerQ.front().first;
        int x = playerQ.front().second.first;        
        int y = playerQ.front().second.second;
        playerQ.pop();

        for(int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isValid(nx, ny, n, m) && vec[nx][ny] != '#' && playerMap[nx][ny] > steps + 1) {
                playerQ.push({steps + 1, {nx, ny}});
                playerMap[nx][ny] = steps + 1;
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << playerMap[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    pair<int, pair<int, int>> ans;
    for(int i = 0; i < n; i++) {

        if(monsterMap[i][0] > playerMap[i][0])
            ans = {playerMap[i][0], {i, 0}};
        if(monsterMap[i][m - 1] > playerMap[i][m - 1]) 
            ans = {playerMap[i][m - 1], {i, m - 1}};
    }

    for(int j = 0; j < m; j++) {

        if(monsterMap[0][j] > playerMap[0][j])
            ans = {playerMap[0][j], {0, j}};
        if(monsterMap[n - 1][j] > playerMap[n - 1][j]) 
            ans = {playerMap[n - 1][j], {n - 1, j}};
    }

    playerQ.push(ans);
    if(ans.first == 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << ans.first << endl;
    string str;
    while(!playerQ.empty()) {

        int steps = playerQ.front().first;
        int x = playerQ.front().second.first;        
        int y = playerQ.front().second.second;
        playerQ.pop();

        for(int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isValid(nx, ny, n, m) && vec[nx][ny] != '#' && playerMap[nx][ny] == steps - 1) {
                playerQ.push({steps - 1, {nx, ny}});

                if(dy[i] == 1) {
                    str.push_back('L');
                } else if(dy[i] == -1) {
                    str.push_back('R');
                } 

                if(dx[i] == 1) {
                    str.push_back('U');
                } else if(dx[i] == -1) {
                    str.push_back('D');
                } 
                break;
            }
        }
    }

    reverse(str.begin(), str.end());
    cout << str << endl;
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