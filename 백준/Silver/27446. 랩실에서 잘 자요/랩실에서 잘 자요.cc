#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int n, m;
    cin >> n >> m;

    vector<bool> pages(m + 1, false);
    for(int i = 0, page; i < m; ++i){
        cin >> page;
        pages[page] = true;
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, inf));
    // dp[i][0] = i페이지를 인쇄하지 않은 경우 잉크 양. 페이지를 인쇄해야만 하는 경우, inf를 넣음
    // dp[i][1] = i페이지를 인쇄한 경우 잉크 양.
    dp[1][0] = pages[1] ? 0 : inf;
    dp[1][1] = 7;

    for(int i = 2; i <= n; ++i){
        dp[i][0] = pages[i] ? min(dp[i - 1][0], dp[i - 1][1]) : inf;
        dp[i][1] = min(dp[i - 1][0] + 7, dp[i - 1][1] + 2);
    }

    cout << min(dp[n][0], dp[n][1]);

    return 0;
}