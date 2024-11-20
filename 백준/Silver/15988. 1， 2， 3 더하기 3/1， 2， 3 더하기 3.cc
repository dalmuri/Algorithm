#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int dp[1'000'001];

int main(){
    FASTIO

    int mod = 1'000'000'009;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        memset(dp, 0, sizeof(int) * (n + 1));
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int num = 1; num <= 3 && i + num <= n; num++){
                dp[i + num] = (dp[i + num] + dp[i]) % mod;
            }
        }

        cout << dp[n] << "\n";
    }

    return 0;
}