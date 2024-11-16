#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int inf = 987654321;
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int> chapters(k + 1);
        for(int i = 1; i <= k; i++) cin >> chapters[i];

        vector<int> prefix_sum(k + 1, 0);
        for(int i = 1; i <= k; i++) prefix_sum[i] += prefix_sum[i - 1] + chapters[i];

        vector<vector<int>> dp(k + 1, vector<int>(k + 1, inf)); // dp[i][j] = [i, j] 챕터를 합치는데 걸리는 비용의 최솟값
        for(int i = 1; i <= k; i++) dp[i][i] = 0;
        for(int len = 2; len <= k; len++){
            for(int start = 1; start + len - 1 <= k; start++){
                int end = start + len - 1;
                for(int mid = start; mid + 1 <= end; mid++){
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + prefix_sum[end] - prefix_sum[start - 1]);
                }
            }
        }

        cout << dp[1][k] << "\n";
    }

    return 0;
}