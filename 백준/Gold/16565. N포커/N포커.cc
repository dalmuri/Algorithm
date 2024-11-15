#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int mod = 10'007;

int main(){
    FASTIO

    int n;
    cin >> n;
 
    vector<vector<int>> nCr(53, vector<int>(53, 1));
    for(int i = 2; i < 53; i++){
        for(int j = 1; j < i; j++){
            nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % mod;
        }
    }

    int answer = 0;
    for(int i = 1; i * 4 <= n; i++){ // i = 4카드가 만들어지는 개수
        if(i & 1) answer += nCr[13][i] * nCr[52 - i * 4][n - i * 4];
        else{
            answer -= (nCr[13][i] * nCr[52 - i * 4][n - i * 4]) % mod;
            answer += mod;
        }

        answer %= mod;
    }

    cout << answer;

    return 0;
}