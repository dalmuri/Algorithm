#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int mod = 1'000'000'003;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    dp[1][1] = 1;

    for(int i = 2; i < n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
        }
    }

    // 첫 색을 사용하는 경우 + 사용하지 않는 경우 
    int answer = (dp[n - 3][k - 1] + dp[n - 1][k]) % mod;
    cout << answer;

    return 0;
}