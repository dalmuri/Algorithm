#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(k + 1, k + 1);
    dp[0] = 0;
    for(int i = 0; i < k + 1; i++){
        for(int coin : coins){
            if(i + coin >= k + 1) continue;

            dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
    }

    if(dp[k] == k + 1) cout << -1;
    else cout << dp[k];

    return 0;
}