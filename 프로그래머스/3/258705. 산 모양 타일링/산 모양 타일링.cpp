#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int mod = 10007;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[i][0] = i번째 역삼각형의 오른쪽 아래가 삼각형 타일로 채워진 경우
    // dp[i][1] = i번째 역삼각형과 오른쪽 아래가 하나의 마름모 타일로 채워진 경우
    dp[0][0] = 2 + tops[0];
    dp[0][1] = 1;
    
    for(int i = 1; i < n; i++){
        dp[i][0] = (dp[i - 1][0] * (2 + tops[i]) + dp[i - 1][1] * (1 + tops[i])) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    
    return (dp[n - 1][0] + dp[n - 1][1]) % mod;
}