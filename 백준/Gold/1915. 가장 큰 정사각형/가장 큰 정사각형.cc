#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n + 1, vector<char>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp[i][j] = (1, 1) ~ (i, j) 까지의 정사각형 중 (i, j)를 포함하는 가장 큰 정사각형의 한 변의 길이
    int answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == '0') continue;

            dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            answer = max(answer, dp[i][j] * dp[i][j]);
        }
    }

    cout << answer;

    return 0;
}