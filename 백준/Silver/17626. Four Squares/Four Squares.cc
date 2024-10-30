#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> squares;
    for(int i = 1; i * i <= n; i++){
        squares.push_back(i * i);
    }

    vector<int> dp(n + 1, 50001);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int sq : squares){
            if(i + sq > n) break;

            dp[i + sq] = min(dp[i + sq], dp[i] + 1);
        }
    }

    cout << dp[n];

    return 0;
}