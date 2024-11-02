#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<vector<int>> dir = {{0, 1}, {1, 0}};

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<long long>> cnt(n, vector<long long>(n, 0));
    cnt[0][0] = 1ll;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0) continue;
            for(vector<int> d : dir){
                int next_r = i + d[0] * board[i][j];
                int next_c = j + d[1] * board[i][j];
                if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) continue;
                cnt[next_r][next_c] += cnt[i][j];
            }
        }
    }

    cout << cnt[n - 1][n - 1];

    return 0;
}