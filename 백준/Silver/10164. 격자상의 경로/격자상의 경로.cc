#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m, k;
    cin >> n >> m >> k;
    
    pair<int, int> mid = {max(0, (k - 1) / m), max(0, (k - 1) % m)};
    pair<int, int> end = {n - 1 - mid.first, m - 1 - mid.second};

    vector<vector<int>> dp(max(mid.first, end.first) + 1, vector<int>(max(mid.second, end.second) + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[mid.first][mid.second] * dp[end.first][end.second];

    return 0;
}