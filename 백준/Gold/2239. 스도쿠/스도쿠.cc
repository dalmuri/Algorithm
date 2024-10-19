#include <string>
#include <iostream>
#include <vector>
#include <map>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool check_row(int r, int c, vector<vector<int>>& board){
    for(int i = 0; i < 9; i++){
        if(i == c) continue;
        if(board[r][i] == board[r][c]) return false;
    }
    return true;
}

bool check_col(int r, int c, vector<vector<int>>& board){
    for(int i = 0; i < 9; i++){
        if(i == r) continue;
        if(board[i][c] == board[r][c]) return false;
    }
    return true;
}

bool check_block(int r, int c, vector<vector<int>>& board){
    for(int i = r - r % 3; i < r - r % 3 + 3; i++){
        for(int j = c - c % 3; j < c - c % 3 + 3; j++){
            if(i == r && j == c) continue;
            if(board[i][j] == board[r][c]) return false;
        }
    }
    return true;
}

bool fill(int r, int c, vector<vector<int>>& sudoku){
    if(r >= 9) return true;
    int next_r = r;
    int next_c = c + 1;
    if(next_c >= 9){
        next_c = 0;
        next_r++;
    }

    if(sudoku[r][c] == 0) {
        for(int n = 1; n <= 9; n++){
            sudoku[r][c] = n;
            if(check_row(r, c, sudoku) && check_col(r, c, sudoku) && check_block(r, c, sudoku)){
                if(fill(next_r, next_c, sudoku)) return true;
            }
        }
        sudoku[r][c] = 0;
        return false;
    }
    else return fill(next_r, next_c, sudoku);
}

int main(){
    FASTIO

    vector<vector<int>> sudoku(9, vector<int>(9));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c;
            cin >> c;
            sudoku[i][j] = c - '0';
        }
    }

    fill(0, 0, sudoku);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j];
        }
        cout << "\n";
    }

    return 0;
}