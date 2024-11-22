#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<bool> is_vip(n + 1, false);
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        is_vip[num] = true;
    }

    vector<int> dp(n + 1, 0); // dp[i] = i개의 연속된 좌석에 앉을 수 있는 경우의 수
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];

    int cnt = 1;
    int answer = 1;
    for(int i = 1; i <= n; i++, cnt++){
        if(is_vip[i]){
            answer *= dp[cnt - 1];
            cnt = 0;
        }
    }
    answer *= dp[cnt - 1];

    cout << answer;

    return 0;
}