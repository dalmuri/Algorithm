#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m, -inf));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        vector<int> right(m, -inf);
        right[0] = dp[i][0] + board[i][0];
        for(int j = 1; j < m; j++){
            right[j] = max(dp[i][j], right[j - 1]) + board[i][j];
        }

        vector<int> left(m, -inf);
        left[m - 1] = dp[i][m - 1] + board[i][m - 1];
        for(int j = m - 2; j >= 0; j--){
            left[j] = max(dp[i][j], left[j + 1]) + board[i][j];
        }

        for(int j = 0; j < m; j++){
            dp[i + 1][j] = max(left[j], right[j]);
        }
    }

    cout << dp[n][m - 1];

    return 0;
}