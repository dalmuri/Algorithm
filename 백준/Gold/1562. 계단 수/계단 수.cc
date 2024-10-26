#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int mod = 1'000'000'000;
    int n;
    cin >> n;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(10, vector<int>(1024, 0)));
    for(int i = 1; i < 10; i++) dp[0][i][1 << i] = 1;
    

    for(int i = 0; i + 1 < n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 1024; k++){
                if(dp[i][j][k] == 0) continue;

                if(j > 0){
                    dp[i + 1][j - 1][k | (1 << (j - 1))] += dp[i][j][k];
                    dp[i + 1][j - 1][k | (1 << (j - 1))] %= mod;
                }

                if(j < 9){
                    dp[i + 1][j + 1][k | (1 << (j + 1))] += dp[i][j][k];
                    dp[i + 1][j + 1][k | (1 << (j + 1))] %= mod;
                }
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += dp[n - 1][i][1023];
        sum %= mod;
    }

    cout << sum;

    return 0;
}