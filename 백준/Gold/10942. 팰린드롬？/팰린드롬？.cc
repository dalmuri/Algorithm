#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) dp[i][i] = true;
    for(int i = 0; i + 1 < n; i++) if(nums[i] == nums[i + 1]) dp[i][i + 1] = true;

    for(int len = 2; len < n; len++){
        for(int i = 0; i + len < n; i++){
            if(dp[i + 1][i + len - 1] && nums[i] == nums[i + len]) dp[i][i + len] = true;
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        cout << (dp[s - 1][e - 1] ? 1 : 0) << "\n";
    }

    return 0;
}