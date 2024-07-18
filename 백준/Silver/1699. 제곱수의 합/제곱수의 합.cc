#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int d = 1; d * d <= i; d++){
            dp[i] = min(dp[i], dp[i - d * d] + 1);
        }
    }
    
    cout << dp[n];

    return 0;
}