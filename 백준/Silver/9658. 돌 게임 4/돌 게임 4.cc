#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<bool> dp(max(n + 1, 6), false); // dp[i] = i개의 돌이 남았을 때 SK 차례이면 승리하는 사람. false = CY, true = SK
    dp[2] = dp[4] = dp[5] = true;
    for(int i = 6; i <= n; ++i){
        if(!(dp[i - 1] && dp[i - 3] && dp[i - 4])) dp[i] = true;
    }

    cout << (dp[n] ? "SK" : "CY");

    return 0;
}