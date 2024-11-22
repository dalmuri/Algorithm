#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int n;
    cin >> n;

    vector<int> maze(n);
    for(int i = 0; i < n; i++) cin >> maze[i];

    vector<int> dp(n, inf);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= maze[i] && i + j < n; j++){
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    cout << (dp[n - 1] < inf ? dp[n - 1] : -1);

    return 0;
}