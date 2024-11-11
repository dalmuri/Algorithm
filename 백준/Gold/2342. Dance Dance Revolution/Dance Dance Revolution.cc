#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int calc_power(int now, int next){
    if(now == next) return 1;
    if(now == 0 || next == 0) return 2;
    if(abs(next - now) == 2) return 4;
    return 3;
}

int main(){
    FASTIO

    int inf = 12345678;
    vector<vector<vector<int>>> dp(100'002, vector<vector<int>>(5, vector<int>(5, inf)));
    dp[0][0][0] = 0;

    int idx = 0;
    int now = 0, next;
    for(; 1; idx++, now = next){
        cin >> next;
        if(next == 0) break;

        for(int l = 0; l < 5; l++){
            if(next != now) dp[idx + 1][next][now] = min(dp[idx + 1][next][now], dp[idx][l][now] + calc_power(l, next));
            if(l != next) dp[idx + 1][l][next] = min(dp[idx + 1][l][next], dp[idx][l][now] + calc_power(now, next));
        }

        for(int r = 0; r < 5; r++){
            if(next != now) dp[idx + 1][now][next] = min(dp[idx + 1][now][next], dp[idx][now][r] + calc_power(r, next));
            if(r != next) dp[idx + 1][next][r] = min(dp[idx + 1][next][r], dp[idx][now][r] + calc_power(now, next));
        }
    }

    int answer = inf;
    for(int l = 0; l < 5; l++) answer = min(answer, dp[idx][l][now]);
    for(int r = 0; r < 5; r++) answer = min(answer, dp[idx][now][r]);

    cout << answer;

    return 0;
}