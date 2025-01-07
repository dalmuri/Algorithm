#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

long long dp[31][31];

int main(){
    FASTIO

    for(int w = 0; w <= 30; w++){
        for(int h = 0; h <= w; h++){
            if(w == 0 || h == 0)
                dp[w][h] = 1;
            else
                dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
        }
    }

    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        cout << dp[n][n] << "\n";
    }

    return 0;
}