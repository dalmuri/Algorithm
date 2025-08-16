#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<pair<int, int>> around = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

bool check(int r, int c, vector<vector<char>>& board){
    vector<pair<int, int>> mines;
    int cnt = board[r][c] - '0';
    for(int i = 0; i < around.size(); ++i){
        int next_r = r + around[i].first;
        int next_c = c + around[i].second;
        if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) continue;

        if(board[next_r][next_c] == '!') cnt--;
        else if(board[next_r][next_c] == '#') mines.push_back({next_r, next_c});
    }

    if(cnt == 0 && mines.size() > 0){
        for(auto [row, col] : mines) board[row][col] = 'X';
        return true;
    }
    else if(mines.size() == cnt && cnt > 0){
        for(auto [row, col] : mines) board[row][col] = '!';
        return true;
    }

    return false;
}

int main(){
    FASTIO

    cin >> n;

    vector<vector<char>> board(n, vector<char>(n));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> board[i][j];

            if(board[i][j] != '#') q.push({i, j});
        }
    }
    
    bool flag = true;
    while(flag && q.size() > 0){
        flag = false;

        int size = q.size();
        while(size--){
            auto [r, c] = q.front();
            q.pop();
            if(check(r, c, board)){
                flag = true;
                q.push({r, c});
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == '#' || board[i][j] == '!') answer++;
        }
    }

    cout << answer;

    return 0;
}