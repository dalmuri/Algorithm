#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<vector<int>> board;

bool able(int r, int c){
    if(board[r][c] != 1) return false;

    for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 2) return false;
    }

    for(int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 2) return false;
    }

    return true;
}

int search(int r, int c, int color){
    int result = 0;

    for(int i = r; i < n; i++){
        int j = (i == r ? c : ((i + color) & 1));
        for(; j < n; j+=2){
            if(!able(i, j)) continue;

            board[i][j] = 2;
            result = max(result, search(i, j + 2, color) + 1);
            board[i][j] = 1;
        }
    }
    
    return result;
}

int main(){
    FASTIO

    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    cout << search(0, 0, 0) + search(0, 1, 1);

    return 0;
}