#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    string s;
    cin >> n >> m >> s;

    int len = n * 2 + 1;
    int answer = 0;
    vector<int> dp(m, 0);
    for(int i = 0; i < m; i++){
        if(s[i] == 'O'){
            if(i > 0 && s[i - 1] == 'I') dp[i] = dp[i - 1] + 1;
        }
        else{
            if(i > 0 && s[i - 1] == 'O') dp[i] = dp[i - 1] + 1;
            else dp[i] = 1;

            if(dp[i] >= len) answer++;
        }
    }

    cout << answer;

    return 0;
}