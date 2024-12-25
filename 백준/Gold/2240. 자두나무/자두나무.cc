#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int t, w;
    cin >> t >> w;

    vector<vector<vector<int>>> dp(t + 1, vector<vector<int>>(2, vector<int>(w + 1, -inf)));
    // dp[i][j][k] = i초에 j위치에서 k번 움직였을 때 받은 자두의 최댓값
    dp[0][0][0] = 0;
    int fruit;
    for(int i = 1; i <= t; i++){
        cin >> fruit;
        fruit--;

        for(int j = 0; j < 2; j++){
            for(int k = 0; k <= w; k++){
                if(k > 0) dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][(j + 1) % 2][k - 1]);
                else dp[i][j][k] = dp[i - 1][j][k];
                
                if(fruit == j) dp[i][j][k]++;
            }
        }
    }

    cout << max(*max_element(dp[t][0].begin(), dp[t][0].end()), *max_element(dp[t][1].begin(), dp[t][1].end()));

    return 0;
}