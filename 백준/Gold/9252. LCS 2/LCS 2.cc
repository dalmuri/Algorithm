#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    vector<vector<int>> dp(a.size(), vector<int>(b.size(), 0));
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<char> ans;
    int i = a.size() - 1, j = b.size() - 1;
    while(dp[i][j] > 0){
        if(dp[i - 1][j] == dp[i][j]) i--;
        else if(dp[i][j - 1] == dp[i][j]) j--;
        else{
            ans.push_back(a[i]);
            i--;
            j--;
        }
    }

    cout << ans.size() << "\n";
    if(ans.size() > 0){
        for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    }

    return 0;
}