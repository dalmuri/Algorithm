#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> scores(n, vector<int>(7));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 7; ++j){
            cin >> scores[i][j];
        }

        sort(scores[i].begin() + 2, scores[i].end(), greater<int>());
    }

    int max_score = 0;
    for(int i = 0; i < n; ++i){
        max_score = max(max_score, max(scores[i][0], scores[i][1]) + scores[i][2] + scores[i][3]);
    }

    cout << max_score;

    return 0;
}