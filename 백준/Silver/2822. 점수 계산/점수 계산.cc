#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    using pii = pair<int, int>;
    vector<pii> scores(8);
    for(int i = 0; i < 8; i++){
        cin >> scores[i].first;
        scores[i].second = i + 1;
    }

    sort(scores.rbegin(), scores.rend());
    sort(scores.begin(), scores.begin() + 5, [](pii a, pii b){
        return a.second < b.second;
    });

    cout << accumulate(scores.begin(), scores.begin() + 5, 0, [](int acc, pii e){ return acc + e.first; }) << "\n";
    for(int i = 0; i < 5; i++) cout << scores[i].second << " ";

    return 0;
}