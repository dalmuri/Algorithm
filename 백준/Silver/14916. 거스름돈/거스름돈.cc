#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;
    int n;
    cin >> n;

    vector<int> dp(n + 1, inf);
    dp[0] = 0;

    for(int i = 0; i + 2 <= n; i++){
        dp[i + 2] = min(dp[i + 2], dp[i] + 1);
        if(i + 5 <= n) dp[i + 5] = min(dp[i + 5], dp[i] + 1);
    }

    cout << (dp[n] < inf ? dp[n] : -1);

    return 0;
}