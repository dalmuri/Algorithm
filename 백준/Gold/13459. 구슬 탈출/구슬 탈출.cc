#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

using pii = pair<int, int>;

const vector<pii> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m;

bool const can_move(pii marble, int dir, vector<vector<char>>& board){
    int next_r = marble.first + direction[dir].first;
    int next_c = marble.second + direction[dir].second;
    if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) return false;
    if(board[next_r][next_c] == '#' || board[next_r][next_c] == 'R' || board[next_r][next_c] == 'B') return false;

    return true;
}

void move_marbles(pii red, pii blue, int dir, vector<vector<char>>& board){
    bool moved = true;
    bool exits_red = false;
    while(moved){
        moved = false;

        if(!exits_red && can_move(red, dir, board)){
            board[red.first][red.second] = '.';
            red.first += direction[dir].first;
            red.second += direction[dir].second;
            
            if(board[red.first][red.second] == 'O') exits_red = true;
            else{
                board[red.first][red.second] = 'R';
                moved = true;
            }
        }

        if(can_move(blue, dir, board)){
            board[blue.first][blue.second] = '.';
            blue.first += direction[dir].first;
            blue.second += direction[dir].second;
            
            if(board[blue.first][blue.second] == 'O') return;
            else{
                board[blue.first][blue.second] = 'B';
                moved = true;
            }
        }
    }
}

bool check(int cnt, pii prev_red, pii prev_blue, vector<vector<char>>& board){
    if(cnt > 10) return false;

    pii red = {-1, -1}, blue = {-1, -1};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'R') red = {i, j};
            else if(board[i][j] == 'B') blue = {i, j};
        }
    }

    if(blue.first == -1) return false;
    if(red.first == -1) return true;
    if(prev_red == red && prev_blue == blue) return false;

    for(int dir = 0; dir < 4; dir++){
        vector<vector<char>> new_board(board);
        move_marbles(red, blue, dir, new_board);
        if(check(cnt + 1, red, blue, new_board)) return true;
    }

    return false;
}

void print(vector<vector<char>>& board){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main(){
    FASTIO

    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    cout << check(0, {-1, -1}, {-1, -1}, board);

    return 0;
}