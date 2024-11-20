#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int max_n = 1'000'001;
int dp[max_n];

int main(){
    FASTIO

    int mod = 1'000'000'009;

    dp[0] = 1;
    for(int i = 0; i < max_n; i++){
        for(int num = 1; num <= 3 && i + num <= max_n; num++){
            dp[i + num] = (dp[i + num] + dp[i]) % mod;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }

    return 0;
}