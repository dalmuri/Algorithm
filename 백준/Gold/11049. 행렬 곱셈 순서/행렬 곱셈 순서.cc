#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> matrix(n);
    for(int i = 0; i < n; i++){
        int r, c;
        cin >> r >> c;
        matrix[i] = {r, c};
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // dp[i][j] = matrix[i] ~ matrix[j] 곱셉 연산 최소 횟수
    for(int i = 0; i < n; i++) dp[i][i] = 0;

    for(int len = 1; len < n; len++){
        for(int i = 0; i + len < n; i++){
            for(int mid = i; mid < i + len; mid++){
                dp[i][i + len] = min(dp[i][i + len], dp[i][mid] + dp[mid + 1][i + len] + matrix[i][0] * matrix[mid][1] * matrix[i + len][1]);
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;
}