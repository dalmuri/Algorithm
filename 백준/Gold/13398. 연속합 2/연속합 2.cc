#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(2));
    // dp[i][0] = 수를 제거하지 않았을 때 [0, i] 번째 수의 합의 최댓값
    // dp[i][1] = 수를 하나 제거했을 때 [0, i] 번째 수의 합의 최댓값
    dp[0][0] = arr[0];
    
    int answer = arr[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][0], 0) + arr[i];
        dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);

        answer = max({answer, dp[i][0], dp[i][1]});
    }

    cout << answer;

    return 0;
}