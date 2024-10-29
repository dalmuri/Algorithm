#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for(int i = 1; i < str1.size() + 1; i++){
        for(int j = 1; j < str2.size() + 1; j++){
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<char> lcs;
    int i = str1.size();
    int j = str2.size();
    while(dp[i][j] > 0){
        if(dp[i - 1][j] == dp[i][j]) i--;
        else if(dp[i][j - 1] == dp[i][j]) j--;
        else{
            lcs.push_back(str1[i - 1]);
            i--;
            j--;
        }
    }

    for(int i = lcs.size() - 1; i >= 0; i--) cout << lcs[i];

    return 0;
}