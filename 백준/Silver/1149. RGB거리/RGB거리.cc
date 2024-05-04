#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){
    FASTIO;
    
    int n;
    cin >> n;
    
    vector<vector<int>> cost(n + 1, vector<int>(3, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            cin >> cost[i][j];
        }
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for(int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
    
    return 0;
}