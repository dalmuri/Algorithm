#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int dp[100'001][3];

int main(){
    FASTIO

    const int mod = 1'000'000'009;

    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][2] = 1;

    for(int i = 1; i <= 100'000; i++){
        for(int num = 1; num <= 3 && i + num <= 100'000; num++){
            if(num - 1 != 0) dp[i + num][num - 1] = (dp[i + num][num - 1] + dp[i][0]) % mod;
            if(num - 1 != 1) dp[i + num][num - 1] = (dp[i + num][num - 1] + dp[i][1]) % mod;
            if(num - 1 != 2) dp[i + num][num - 1] = (dp[i + num][num - 1] + dp[i][2]) % mod;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << accumulate(dp[n], dp[n] + 3, 0, [](int acc, int e){ return (acc + e) % mod; }) << "\n";
    }

    return 0;
}