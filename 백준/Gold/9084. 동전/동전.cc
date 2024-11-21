#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int coins[20];
int dp[10'001];

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> coins[i];
        cin >> m;

        memset(dp + 1, 0, sizeof(int) * m);
        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j + coins[i] <= m; j++){
                dp[j + coins[i]] += dp[j];
            }
        }

        cout << dp[m] << "\n";
    }

    return 0;
}