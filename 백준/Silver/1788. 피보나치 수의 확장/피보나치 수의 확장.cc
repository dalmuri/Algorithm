#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int mod = 1'000'000'000;

    int n;
    cin >> n;

    vector<int> dp(abs(n) + 1, 0);

    if(n > 0){
        dp[1] = 1;

        for(int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    else if(n < 0){
        dp[1] = 1;

        for(int i = 2; i <= -n; i++){
            dp[i] = dp[i - 2] - dp[i - 1];
            
            if(dp[i] >= 0) dp[i] %= mod;
            else dp[i] = (-dp[i]) % mod * (-1);
        }
    }

    int answer = dp[abs(n)];
    if(answer > 0){
        cout << "1\n" << answer;
    }
    else if(answer < 0){
        cout << "-1\n" << -answer;
    }
    else{
        cout << "0\n" << answer;
    }

    return 0;
}