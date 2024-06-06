#include <bits/stdc++.h>
using namespace std;

int dirx[] = {1, 0, -1, 0};
int diry[] = {0, 1, 0, -1};
char dirL[] = {'R', 'D', 'L', 'U'};

bool check(int i, int j, int n, int m) {

    if(i >= 0 && j >= 0 && i < n && j < m) 
        return 1;
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    queue<pair<int, int>> qu;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vec[i][j] == 'A') {
                qu.push({i, j});
                a = i, b = j;
                vec[i][j] = '#';
            }
        }
    }

    // BFS
    vector<vector<char>> direction(n, vector<char> (m));
    string path = "";
    while(!qu.empty()) {

        auto front = qu.front();
        qu.pop();

        if(vec[front.first][front.second] == 'B') {
            int i = front.first, j = front.second;

            while(i != a || j != b) {

                if(direction[i][j] == 'L') {
                    j++;
                    path.push_back('L');
                }
                else if(direction[i][j] == 'R') {
                    j--;
                    path.push_back('R');
                }
                else if(direction[i][j] == 'D') {
                    i--;
                    path.push_back('D');
                }
                else if(direction[i][j] == 'U') {
                    i++;
                    path.push_back('U');
                }
            }

            break;
        }

        for(int k = 0; k < 4; k++) {

            int ni = front.first + diry[k];
            int nj = front.second + dirx[k];

            if(check(ni, nj, n, m) && vec[ni][nj] != '#') {

                qu.push({ni, nj});
                direction[ni][nj] = dirL[k];

                if(vec[ni][nj] != 'B') 
                    vec[ni][nj] = '#';
            }
        }
    }

    if(path.size() != 0) {
        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        cout << path << endl; 
    } else {
        cout << "NO" << endl;
    }
    
}