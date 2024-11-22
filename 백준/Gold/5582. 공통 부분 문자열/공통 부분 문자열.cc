#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), 0));

    int answer = 0;
    for(int i = 0; i < str1.size(); i++){
        for(int j = 0; j < str2.size(); j++){
            if(str1[i] == str2[j]){
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j - 1] + 1;

                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << answer;

    return 0;
}