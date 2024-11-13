#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
const int mod = 10;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> board;
vector<vector<bool>> visited;

void count0(int r, int c){
    queue<pair<int, int>> q;
    queue<pair<int, int>> wallq;
    q.push({r, c});
    visited[r][c] = true;
    int count = 1;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(vector<int> d : dir){
            int next_row = row + d[0];
            int next_col = col + d[1];
            if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
            if(visited[next_row][next_col]) continue;

            visited[next_row][next_col] = true;
            if(board[next_row][next_col] > 0){
                wallq.push({next_row, next_col});
                continue;
            }

            count++;
            q.push({next_row, next_col});
        }
    }

    while(!wallq.empty()){
        int row = wallq.front().first;
        int col = wallq.front().second;
        wallq.pop();

        board[row][col] += count;

        visited[row][col] = false;
    }
}

int main(){
    FASTIO

    cin >> n >> m;

    board = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] > 0) continue;
            if(visited[i][j]) continue;

            count0(i, j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] % 10;
        }
        cout << "\n";
    }

    return 0;
}