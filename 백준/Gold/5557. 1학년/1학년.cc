#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<long long>> dp(n - 1, vector<long long>(21, 0ll));
    dp[0][nums[0]] = 1ll;

    for(int i = 1; i < n - 1; i++){
        for(int prev = 0; prev <= 20; prev++){
            if(dp[i - 1][prev] == 0ll) continue;

            int num = prev + nums[i];
            if(0 <= num && num <= 20) dp[i][num] += dp[i - 1][prev];

            num = prev - nums[i];
            if(0 <= num && num <= 20) dp[i][num] += dp[i - 1][prev];
        }
    }

    cout << dp[n - 2][nums[n - 1]];

    return 0;
}