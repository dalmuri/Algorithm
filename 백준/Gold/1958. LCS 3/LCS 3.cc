#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int dp[101][101][101];

int main(){
    FASTIO

    array<string, 3> arr = {"_", "_", "_"};
    for(int i = 0; i < 3; i++){
        string str;
        cin >> str;

        arr[i] += str;
    }

    int answer = 0;
    for(int i = 1; i < arr[0].size(); i++){
        for(int j = 1; j < arr[1].size(); j++){
            for(int k = 1; k < arr[2].size(); k++){
                if(arr[0][i] == arr[1][j] && arr[0][i] == arr[2][k]){
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else{
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }

                answer = max(answer, dp[i][j][k]);
            }
        }
    }

    cout << answer;

    return 0;
}