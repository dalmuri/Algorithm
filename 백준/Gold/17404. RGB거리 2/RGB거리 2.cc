#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int inf = 987654321;

    int n;
    cin >> n;

    vector<vector<int>> costs(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> costs[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(3, 0));
    int answer = inf;
    for(int start = 0; start < 3; start++){
        for(int j = 0; j < 3; j++){
            if(start == j) dp[0][j] = costs[0][j];
            else dp[0][j] = inf;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = costs[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
            }
        }

        for(int j = 0; j < 3; j++){
            if(start == j) continue;
            answer = min(answer, dp[n - 1][j]);
        }
    }

    cout << answer;

    return 0;
}