#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<vector<long long>> dp(65, vector<long long>(10, 0ll)); // dp[i][j] = i자리의 수의 가장 오른쪽 숫자가 j일 때의 개수
    dp[0][0] = 1;
    for(int i = 1; i < dp.size(); ++i){
        for(int j = 0; j < 10; ++j){
            dp[i][j] = accumulate(dp[i - 1].begin(), dp[i - 1].begin() + j + 1, 0ll);
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << accumulate(dp[n].begin(), dp[n].end(), 0ll) << "\n";
    }

    return 0;
}