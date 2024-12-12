#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int r, c;
char ground[10'000][500];

bool check(int row, int col){
    if(row < 0 || row >= r) return false;
    if(ground[row][col] == 'x') return false;
    if(ground[row][col] == 'o') return false;
    if(col == c - 1){
        ground[row][col] = 'o';
        return true;
    }

    for(int i = -1; i <= 1; i++){
        if(check(row + i, col + 1)){
            ground[row][col] = 'o';
            return true;
        }
    }

    ground[row][col] = 'x';
    return false;
}

int main(){
    FASTIO

    cin >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> ground[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i < r; i++){
        if(check(i, 0)) answer++;
    }

    cout << answer;

    return 0;
}