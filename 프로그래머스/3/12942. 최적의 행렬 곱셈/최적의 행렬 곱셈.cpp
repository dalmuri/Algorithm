#include <string>
#include <vector>
#include <climits>

using namespace std;

int calc(int start, int end, vector<vector<int>>& dp, vector<vector<int>>& matrix_sizes){
    for(int k = start; k < end; k++){
        int cnt1 = dp[start][k] != INT_MAX ? dp[start][k] : calc(start, k, dp, matrix_sizes);
        int cnt2 = dp[k + 1][end] != INT_MAX ? dp[k + 1][end] : calc(k + 1, end, dp, matrix_sizes);
        
        int result = cnt1 + cnt2 + matrix_sizes[start][0] * matrix_sizes[k][1] * matrix_sizes[end][1];
        dp[start][end] = min(dp[start][end], result);
    }
    
    return dp[start][end];
}

int solution(vector<vector<int>> matrix_sizes) {
    vector<vector<int>> dp(matrix_sizes.size(), vector<int>(matrix_sizes.size(), INT_MAX));
    for(int i = 0; i < matrix_sizes.size(); i++) dp[i][i] = 0;
    
    int answer = calc(0, matrix_sizes.size() - 1, dp, matrix_sizes);
    return answer;
}