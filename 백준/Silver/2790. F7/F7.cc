#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> scores(n);
    for(int i = 0; i < n; ++i) cin >> scores[i];

    sort(scores.rbegin(), scores.rend());

    int best_score = scores[0] + 1, answer = 1;
    for(; answer < n; ++answer){
        if(best_score > scores[answer] + n){
            break;
        }

        best_score = max(best_score, scores[answer] + answer + 1);
    }

    cout << answer;

    return 0;
}