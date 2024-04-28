#include <iostream>
#include <string>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){
    FASTIO;
    
    vector<vector<int>> nCr(31, vector<int>(31, 1));
    for(int n = 2; n <= 30; n++){
        for(int r = 1; r < n; r++){
            nCr[n][r] = nCr[n - 1][r - 1] + nCr[n - 1][r];
        }
    }
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        cout << nCr[m][n] << "\n";
    }
    
    return 0;
}