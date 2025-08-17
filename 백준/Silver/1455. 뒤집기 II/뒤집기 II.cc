#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void flip(int r, int c, vector<vector<bool>>& coins){
    for(int i = 0; i <= r; ++i){
        for(int j = 0; j <= c; ++j){
            coins[i][j] = coins[i][j] ^ true;
        }
    }
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> coins(n, vector<bool>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char coin;
            cin >> coin;
            coins[i][j] = coin - '0';
        }
    }

    int answer = 0;
    for(int i = n - 1; i >= 0; --i){
        for(int j = m - 1; j >= 0; --j){
            if(coins[i][j]) flip(i, j, coins), answer++;
        }
    }

    cout << answer;

    return 0;
}