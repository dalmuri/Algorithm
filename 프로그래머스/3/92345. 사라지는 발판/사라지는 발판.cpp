#include <string>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool can_move(int r, int c, vector<vector<int>>& board){
    for(vector<int> d : dir){
        int next_r = r + d[0];
        int next_c = c + d[1];
        
        if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) continue;
        if(board[next_r][next_c]) return true;
    }
    return false;
}

// player 1이 움직이는 턴이라고 가정
// return {승리 가능 여부, 승/패까지 걸리는 턴}
pair<bool, int> play(int r1, int c1, int r2, int c2, vector<vector<int>>& board){
    if(!can_move(r1, c1, board)) return {false, 0};
    if(r1 == r2 && c1 == c2) return {true, 1};
    
    bool can_win = false;
    int lose_turn = 1, win_turn = 100;
    for(vector<int> d : dir){
        int next_r1 = r1 + d[0];
        int next_c1 = c1 + d[1];
        
        if(next_r1 < 0 || next_r1 >= n || next_c1 < 0 || next_c1 >= m) continue;
        if(board[next_r1][next_c1] == 0) continue;
        
        board[r1][c1] = 0;
        auto [is_p2_win, t] = play(r2, c2, next_r1, next_c1, board);
        board[r1][c1] = 1;
        
        if(is_p2_win){
            lose_turn = max(lose_turn, t + 1);
        }
        else{
            can_win = true;
            win_turn = min(win_turn, t + 1);
        }
    }
    
    if(can_win) return {true, win_turn};
    else return {false, lose_turn};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    
    return play(aloc[0], aloc[1], bloc[0], bloc[1], board).second;
}