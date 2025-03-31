#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, t;
    cin >> n >> t;

    vector<vector<int>> study(n, vector<int>(t + 1, 0)); // study[i][j] = [0, i]까지의 단원을 j시간 동안 공부했을 때의 최대 점수
    
    int k0, s0;
    cin >> k0 >> s0;
    for(int j = k0; j <= t; ++j) study[0][j] = s0;

    for(int i = 1; i < n; ++i){
        int k, s;
        cin >> k >> s;

        for(int j = 0; j <= t; ++j){
            study[i][j] = study[i - 1][j];
            if(j - k >= 0) study[i][j] = max(study[i][j], study[i - 1][j - k] + s);
        }
    }

    cout << study[n - 1][t];

    return 0;
}