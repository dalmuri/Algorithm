#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int r, c;
    cin >> r >> c;

    vector<pair<int, int>> rank(9);
    for(int i = 0; i < r; ++i){
        string line;
        cin >> line;

        for(int j = 1; j < line.size(); ++j){
            if('1' <= line[j] && line[j] <= '9'){
                rank[line[j] - '1'] = {j, line[j] - '1'};
                break;
            }
        }
    }

    sort(rank.rbegin(), rank.rend());

    vector<int> answer(9);
    answer[rank[0].second] = 1;
    for(int i = 1, last = 1; i < 9; ++i){
        answer[rank[i].second] = (rank[i - 1].first > rank[i].first) ? ++last : last;
    }

    for(int i = 0; i < 9; ++i) cout << answer[i] << "\n";

    return 0;
}