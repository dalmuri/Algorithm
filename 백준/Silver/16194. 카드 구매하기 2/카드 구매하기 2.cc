#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int n;
    cin >> n;

    vector<int> costs(n + 1);
    for(int i = 1; i <= n; i++) cin >> costs[i];

    vector<int> dp(n + 1, inf);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int card = 1; i + card <= n; card++){
            dp[i + card] = min(dp[i + card], dp[i] + costs[card]);
        }
    }

    cout << dp[n];

    return 0;
}