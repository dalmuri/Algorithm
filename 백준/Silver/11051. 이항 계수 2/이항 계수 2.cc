#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int mod = 10007;
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> nCr(n + 1, vector<int>(n + 1, 1));
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
        }
    }
    
    cout << nCr[n][k];

    return 0;
}