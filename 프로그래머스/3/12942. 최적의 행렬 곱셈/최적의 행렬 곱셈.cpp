#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int inf = 987654321;
    int n = matrix_sizes.size();
    vector<vector<int>> dp(matrix_sizes.size(), vector<int>(n, inf));
    // dp[i][j] = i번 행렬부터 j번 행렬까지 곱한 연산 횟수의 최솟값
    
    for(int i = 0; i < n; i++) dp[i][i] = 0;
    for(int len = 1; len < n; len++){
        for(int i = 0; i + len < n; i++){
            for(int j = i; j < i + len; j++){
                dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j + 1][i + len] + matrix_sizes[i][0] * matrix_sizes[j][1] * matrix_sizes[i + len][1]);
            }
        }
    }
    return dp[0][n - 1];
}