#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n;
int forest[501][501];
int dp[501][501];

int dfs(int r, int c){
    if(dp[r][c] > 0) return dp[r][c];
    dp[r][c] = 1;

    for(auto [dr, dc] : dir){
        int next_r = r + dr;
        int next_c = c + dc;
        if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) continue;
        if(forest[r][c] > forest[next_r][next_c]){
            dp[r][c] = max(dp[r][c], dfs(next_r, next_c) + 1);
        }
    }

    return dp[r][c];
}

int main(){
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> forest[i][j];
        }
    }

    int answer = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer = max(answer, dfs(i, j));
        }
    }

    cout << answer;

    return 0;
}