#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> counsels(n + 1, vector<int>(2));
    for(int i = 1; i <= n; i++) cin >> counsels[i][0] >> counsels[i][1];

    vector<int> dp(n + 2, 0);
    int answer = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i], dp[i - 1]);
        int end_day = i + counsels[i][0];
        if(end_day <= n + 1){
            dp[end_day] = max(dp[end_day], dp[i] + counsels[i][1]);
            answer = max(answer, dp[end_day]);
        }
    }
    
    cout << answer;

    return 0;
}