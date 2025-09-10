#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int mod = 1'000'000'007;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));
    board[0][0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(i > 0) board[i][j] = (board[i][j] + board[i - 1][j]) % mod;
            if(j > 0) board[i][j] = (board[i][j] + board[i][j - 1]) % mod;
            if(i > 0 && j > 0) board[i][j] = (board[i][j] + board[i - 1][j - 1]) % mod;
        }
    }

    cout << board[n - 1][m - 1];

    return 0;
}