#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, l;
int board[100][100];

int check_row(int row){
    vector<bool> placed(n, false);
    for(int i = 1; i < n; i++){
        if(abs(board[row][i] - board[row][i - 1]) > 1) return 0;
        
        if(board[row][i - 1] < board[row][i]){
            if(i < l) return 0;
            for(int j = i - l; j < i; j++){
                if(board[row][j] != board[row][i] - 1) return 0;
                if(placed[j]) return 0;
                placed[j] = true;
            }
        }
        if(board[row][i - 1] > board[row][i]){
            if(i - 1 + l >= n) return 0;
            for(int j = i - 1 + l; j > i - 1; j--){
                if(board[row][j] != board[row][i - 1] - 1) return 0;
                if(placed[j]) return 0;
                placed[j] = true;
            }
        }
    }
    return 1;
}

int check_col(int col){
    vector<bool> placed(n, false);
    for(int i = 1; i < n; i++){
        if(abs(board[i][col] - board[i - 1][col]) > 1) return 0;
        
        if(board[i - 1][col] < board[i][col]){
            if(i < l) return 0;
            for(int j = i - l; j < i; j++){
                if(board[j][col] != board[i][col] - 1) return 0;
                if(placed[j]) return 0;
                placed[j] = true;
            }
        }
        if(board[i - 1][col] > board[i][col]){
            if(i - 1 + l >= n) return 0;
            for(int j = i - 1 + l; j > i - 1; j--){
                if(board[j][col] != board[i - 1][col] - 1) return 0;
                if(placed[j]) return 0;
                placed[j] = true;
            }
        }
    }
    return 1;
}

int main(){
    FASTIO

    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++) answer += check_row(i) + check_col(i);

    cout << answer;

    return 0;
}