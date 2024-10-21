#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int mod = 1'000'000'000;
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); // dp[i][j] = 정수 j개를 더해 i를 만드는 경우의 수
    dp[0][0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < k; j++){
            for(int c = 0; c <= n; c++){
                if(i + c >= n + 1) continue;
                dp[i + c][j + 1] += dp[i][j];
                dp[i + c][j + 1] %= mod;
            }
        }
    }

    cout << dp[n][k];

    return 0;
}