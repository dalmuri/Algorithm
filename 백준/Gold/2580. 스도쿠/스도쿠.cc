#include <string>
#include <iostream>
#include <vector>
#include <map>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int sudoku[9][9];

bool check_row(int r, int c){
    for(int i = 0; i < 9; i++){
        if(i == c) continue;
        if(sudoku[r][i] == sudoku[r][c]) return false;
    }
    return true;
}

bool check_col(int r, int c){
    for(int i = 0; i < 9; i++){
        if(i == r) continue;
        if(sudoku[i][c] == sudoku[r][c]) return false;
    }
    return true;
}

bool check_block(int r, int c){
    for(int i = r - r % 3; i < r - r % 3 + 3; i++){
        for(int j = c - c % 3; j < c - c % 3 + 3; j++){
            if(i == r && j == c) continue;
            if(sudoku[i][j] == sudoku[r][c]) return false;
        }
    }
    return true;
}

bool fill(int idx, vector<pair<int, int>>& to_fill){
    if(idx == to_fill.size()) return true;

    auto [r, c] = to_fill[idx];
    for(int i = 1; i <= 9; i++){
        sudoku[r][c] = i;
        if(check_row(r, c) && check_col(r, c) && check_block(r, c)){
            if(fill(idx + 1, to_fill)) return true;
        }
    }

    sudoku[r][c] = 0;
    return false;
}

int main(){
    FASTIO

    vector<pair<int, int>> to_fill;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku[i][j];

            if(sudoku[i][j] == 0) to_fill.push_back({i, j});
        }
    }

    fill(0, to_fill);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}