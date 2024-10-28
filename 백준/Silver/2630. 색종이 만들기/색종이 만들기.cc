#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void count(int r, int c, int size, vector<vector<int>>& papers, vector<int>& answer){
    if(size == 1){
        answer[papers[r][c]]++;
        return;
    }

    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            if(papers[i][j] == papers[r][c]) continue;

            count(r, c, size / 2, papers, answer);
            count(r, c + size / 2, size / 2, papers, answer);
            count(r + size / 2, c, size / 2, papers, answer);
            count(r + size / 2, c + size / 2, size / 2, papers, answer);
            return;
        }
    }

    answer[papers[r][c]]++;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> papers(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> papers[i][j];
        }
    }

    vector<int> answer(2, 0);
    count(0, 0, n, papers, answer);

    cout << answer[0] << "\n" << answer[1];

    return 0;
}