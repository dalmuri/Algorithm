#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int mod = 1'000'000'000;

    int n;
    cin >> n;

    int sign = 1;
    if(n < 0){
        n *= -1;
        if(!(n & 1)) sign = -1;
    }
    else if(n == 0){
        sign = 0;
    }

    vector<int> dp(n + 2, 0);
    dp[1] = 1;
    for(int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

    cout << sign << "\n" << dp[n];

    return 0;
}