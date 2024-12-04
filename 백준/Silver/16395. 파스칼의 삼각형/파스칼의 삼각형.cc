#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<vector<int>> nCr(n, vector<int>(k, 1));
    for(int i = 2; i < n; i++){
        for(int j = 1; j < i && j < k; j++){
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
        }
    }

    cout << nCr[n - 1][k - 1];

    return 0;
}