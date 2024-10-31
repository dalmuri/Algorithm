#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void fill_triangle(int r, int c, vector<vector<char>>& img){
    if(r >= img.size() || c >= img[0].size()) return;
    img[r][c] = '*';
    img[r + 1][c - 1] = '*';
    img[r + 1][c + 1] = '*';
    for(int i = 0; i < 5; i++) img[r + 2][c - 2 + i] = '*';
}

void dfs(int r, int c, int level, vector<vector<char>>& img){
    if(r >= img.size() || c >= img[0].size()) return;
    if(level == 0){
        fill_triangle(r, c, img);
        return;
    }

    dfs(r, c, level - 1, img);
    dfs(r + 3 * (1 << (level - 1)), c - 3 * (1 << (level - 1)), level - 1, img);
    dfs(r + 3 * (1 << (level - 1)), c + 3 * (1 << (level - 1)), level - 1, img);
}

int main(){
    FASTIO

    int n;
    cin >> n;
    int k = log2(n / 3);

    vector<vector<char>> img(n, vector<char>(n * 2 - 1, ' '));
    dfs(0, img[0].size() / 2, k + 1, img);

    for(int i = 0; i < img.size(); i++){
        for(int j = 0; j < img[0].size(); j++){
            cout << img[i][j];
        }
        cout << "\n";
    }

    return 0;
}