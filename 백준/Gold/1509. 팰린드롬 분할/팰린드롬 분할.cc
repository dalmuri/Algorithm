#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int inf = 123456789;
    string str;
    cin >> str;

    int n = str.size();

    vector<vector<bool>> is_pal(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) is_pal[i][i] = true;
    for(int i = 0; i + 1 < n; i++) if(str[i] == str[i + 1]) is_pal[i][i + 1] = true;

    for(int len = 2; len < n; len++){
        for(int i = 0; i + len < n; i++){
            if(is_pal[i + 1][i + len - 1] && str[i] == str[i + len]) is_pal[i][i + len] = true;
        }
    }

    vector<int> dp(n, inf);
    for(int end = 0; end < n; end++){
        for(int start = 0; start <= end; start++){
            if(is_pal[start][end]) dp[end] = min(dp[end], (start > 0 ? dp[start - 1] + 1 : 1));
        }
    }

    cout << dp[n - 1];

    return 0;
}