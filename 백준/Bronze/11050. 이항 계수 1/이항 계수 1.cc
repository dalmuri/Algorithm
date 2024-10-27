#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<vector<int>> nCr(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                nCr[i][j] = 1;
                continue;
            }

            nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }

    cout << nCr[n][k];

    return 0;
}