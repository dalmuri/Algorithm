#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> papers(7, 0);
    for(int i = 1; i <= 6; ++i) cin >> papers[i];

    int answer = papers[6];

    if(papers[5] > 0){
        answer += papers[5];
        papers[1] = max(0, papers[1] - papers[5] * 11);
    }

    if(papers[4] > 0){
        answer += papers[4];

        if(papers[2] >= 5 * papers[4]){
            papers[2] -= 5 * papers[4];
        }
        else{
            int board = 20 * papers[4] - 4 * papers[2];
            papers[2] = 0;

            papers[1] -= min(papers[1], board);
        }
    }
    
    answer += papers[3] / 4;
    papers[3] %= 4;
    if(papers[3] > 0){
        answer++;

        int board = 36 - 9 * papers[3];
        int cnt2 = papers[3] == 1 ? 5 : papers[3] == 2 ? 3 : 1; // 1->5, 2->3, 3->1

        cnt2 = min(cnt2, papers[2]);
        papers[2] -= cnt2;
        board -= 4 * cnt2;

        papers[1] -= min(papers[1], board);
    }

    answer += papers[2] / 9;
    papers[2] %= 9;
    if(papers[2] > 0){
        answer++;

        papers[1] -= min(papers[1], 36 - 4 * papers[2]);
    }

    answer += papers[1] / 36;
    papers[1] %= 36;
    if(papers[1] > 0) answer++;

    cout << answer;

    return 0;
}