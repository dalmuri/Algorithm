#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<vector<int>> walls;
vector<vector<vector<int>>> dp;

int calc(int r, int c, int dir){
    if(r < 1 || r > n || c < 1 || c > n) return 0;
    if(dp[r][c][dir] >= 0) return dp[r][c][dir];
    
    if(dir == 0){ // 가로
        if(c >= n) dp[r][c][dir] = 0;
        else if(walls[r][c] || walls[r][c + 1]) dp[r][c][dir] = 0;
        else dp[r][c][dir] = calc(r, c - 1, 0) + calc(r - 1, c - 1, 2);
    }
    else if(dir == 1){ // 세로
        if(r >= n) dp[r][c][dir] = 0;
        else if(walls[r][c] || walls[r + 1][c]) dp[r][c][dir] = 0;
        else dp[r][c][dir] = calc(r - 1, c, 1) + calc(r - 1, c - 1, 2);
    }
    else{ // 대각선
        if(r >= n || c >= n) dp[r][c][dir] = 0;
        else if(walls[r][c] || walls[r][c + 1] || walls[r + 1][c] || walls[r + 1][c + 1]) dp[r][c][dir] = 0;
        else dp[r][c][dir] = calc(r, c - 1, 0) + calc(r - 1, c, 1) + calc(r - 1, c - 1, 2);
    }

    return dp[r][c][dir];
}

int main(){
    FASTIO

    cin >> n;

    walls = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            cin >> walls[i][j];
        }
    }

    dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));
    // dp[i][j][k] = walls[i][j]에 파이프의 왼쪽 끝이 k 방향으로 놓여 있는 경우의 수
    // k: 0=가로 1=세로 2=대각선
    // 값이 -1이면 아직 연산되지 않음을 나타냄
    dp[1][1][0] = 1;

    cout << calc(n, n - 1, 0) + calc(n - 1, n, 1) + calc(n - 1, n - 1, 2);

    return 0;
}