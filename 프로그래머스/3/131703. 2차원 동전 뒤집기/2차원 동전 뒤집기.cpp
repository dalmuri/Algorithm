#include <string>
#include <vector>

using namespace std;
int inf = 100;

void overturn_row(int r, vector<vector<int>>& board){
    for(int i = 0; i < board[r].size(); i++){
        board[r][i] = (board[r][i] + 1) % 2;
    }
}

void overturn_col(int c, vector<vector<int>>& board){
    for(int i = 0; i < board.size(); i++){
        board[i][c] = (board[i][c] + 1) % 2;
    }
}

int overturn(vector<vector<int>> board, vector<vector<int>>& target){ // 0행 고정
    int cnt = 0;
    
    for(int c = 0; c < board[0].size(); c++){
        if(board[0][c] != target[0][c]){
            overturn_col(c, board);
            cnt++;
        }
    }
    
    for(int r = 1; r < board.size(); r++){
        if(board[r][0] != target[r][0]){
            overturn_row(r, board);
            cnt++;
        }
    }
    
    for(int r = 0; r < board.size(); r++){
        for(int c = 0; c < board[0].size(); c++){
            if(board[r][c] != target[r][c]) return inf;
        }
    }
    
    return cnt;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = inf;
    
    answer = min(answer, overturn(beginning, target));
    
    overturn_row(0, beginning);
    answer = min(answer, overturn(beginning, target) + 1);
    
    if(answer >= inf) return -1;
    return answer;
}