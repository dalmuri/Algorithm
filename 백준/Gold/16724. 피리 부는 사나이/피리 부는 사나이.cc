#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<char>> board;
vector<vector<int>> zone;

int search(int r, int c){
    if(zone[r][c] == 1) return 1;
    if(zone[r][c] == 2) return 0;

    char dir = board[r][c];
    int next_r = r;
    int next_c = c;

    if(dir == 'U') next_r -= 1;
    else if(dir == 'D') next_r += 1;
    else if(dir == 'R') next_c += 1;
    else next_c -= 1;


    zone[r][c] = 1;
    int res = search(next_r, next_c);
    zone[r][c] = 2;

    return res;
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;
    
    board = vector<vector<char>>(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    zone = vector<vector<int>>(n, vector<int>(m, 0));
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(zone[i][j] > 0) continue;

            answer += search(i, j);
        }
    }

    cout << answer;

    return 0;
}