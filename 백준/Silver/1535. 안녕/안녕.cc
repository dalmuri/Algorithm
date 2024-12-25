#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int n;
    cin >> n;

    vector<int> life(n + 1);
    for(int i = 0; i < n; i++) cin >> life[i];

    vector<int> happy(n + 1);
    for(int i = 0; i < n; i++) cin >> happy[i];

    vector<vector<int>> dp(n + 1, vector<int>(101, -inf));
    dp[0][100] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 100; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j - life[i] > 0) dp[i + 1][j - life[i]] = max(dp[i + 1][j - life[i]], dp[i][j] + happy[i]);
        }
    }

    cout << *max_element(dp[n].begin() + 1, dp[n].end());

    return 0;
}