#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int dp[1'500'002];

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0;
    for(int i = 1; i <= n; i++){
        int t, p;
        cin >> t >> p;

        dp[i] = max(dp[i], dp[i - 1]);
        int end_day = i + t;
        if(end_day <= n + 1){
            dp[end_day] = max(dp[end_day], dp[i] + p);
            answer = max(answer, dp[end_day]);
        }
    }
    
    cout << answer;

    return 0;
}