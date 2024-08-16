#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int mod = 1'000'000'007;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int coin : money){
        for(int i = 0; i + coin <= n; i++){
            dp[i + coin] = (dp[i + coin] + dp[i]) % mod;
        }
    }

    return dp[n];
}