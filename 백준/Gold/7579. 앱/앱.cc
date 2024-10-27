#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int check(vector<vector<int>>& apps, vector<int>& dp){
    int result = 10001;
    for(vector<int> app : apps){
        for(int i = dp.size() - 1; i - app[1] >= 0; i--){
            dp[i] = max(dp[i], dp[i - app[1]] + app[0]);

            if(dp[i] >= m) result = min(result, i);
        }
    }

    return result;
}

int main(){
    FASTIO

    cin >> n >> m;

    vector<vector<int>> apps(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> apps[i][0]; // memory
    for(int i = 0; i < n; i++) cin >> apps[i][1]; // cost

    vector<int> dp(10001, 0); // dp[i] = i의 비용으로 확보할 수 있는 메모리의 최댓값

    cout << check(apps, dp);

    return 0;
}