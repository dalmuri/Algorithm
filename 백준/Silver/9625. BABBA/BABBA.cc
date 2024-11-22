#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int k;
    cin >> k;

    vector<pair<int, int>> dp(k + 1);
    dp[0] = {1, 0};

    for(int i = 1; i <= k; i++){
        dp[i].first = dp[i - 1].second;
        dp[i].second = dp[i - 1].first + dp[i - 1].second;
    }

    cout << dp[k].first << " " << dp[k].second;

    return 0;
}