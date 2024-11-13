#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void next(int &r, int &c, char dir){
    if(dir == 'U') r -= 1;
    else if(dir == 'D') r += 1;
    else if(dir == 'R') c += 1;
    else c -= 1;
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<int>> zone(n, vector<int>(m, 0));
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(zone[i][j] > 0) continue;

            int r = i, c = j;
            while(zone[r][c] == 0){
                zone[r][c] = 1;
                next(r, c, board[r][c]);
            }

            if(zone[r][c] == 1) answer++;

            r = i, c = j;
            while(zone[r][c] == 1){
                zone[r][c] = 2;
                next(r, c, board[r][c]);
            }
        }
    }

    cout << answer;

    return 0;
}