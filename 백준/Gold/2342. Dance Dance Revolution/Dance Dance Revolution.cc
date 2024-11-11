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
    int left = 0, right = 0;
    vector<int> dir = {0};
    while(true){
        int d;
        cin >> d;
        if(d == 0) break;
        dir.push_back(d);
    }

    vector<vector<vector<int>>> dp(dir.size(), vector<vector<int>>(5, vector<int>(5, inf)));
    dp[0][0][0] = 0;

    for(int i = 0; i + 1 < dir.size(); i++){
        int now = dir[i];
        int next = dir[i + 1];

        for(int l = 0; l < 5; l++){
            if(next != now) dp[i + 1][next][now] = min(dp[i + 1][next][now], dp[i][l][now] + calc_power(l, next));
            if(l != next) dp[i + 1][l][next] = min(dp[i + 1][l][next], dp[i][l][now] + calc_power(now, next));
        }

        for(int r = 0; r < 5; r++){
            if(next != now) dp[i + 1][now][next] = min(dp[i + 1][now][next], dp[i][now][r] + calc_power(r, next));
            if(r != next) dp[i + 1][next][r] = min(dp[i + 1][next][r], dp[i][now][r] + calc_power(now, next));
        }
    }

    int answer = inf;
    for(int l = 0; l < 5; l++) answer = min(answer, dp[dir.size() - 1][l][dir.back()]);
    for(int r = 0; r < 5; r++) answer = min(answer, dp[dir.size() - 1][dir.back()][r]);

    cout << answer;

    return 0;
}