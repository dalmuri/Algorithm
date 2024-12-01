#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> dp(10'001, 0);
    dp[0] = 1;

    for(int i = 1; i <= 3; i++){
        for(int j = 0; i + j <= 10'000; j++){
            dp[i + j] += dp[j];
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }

    return 0;
}