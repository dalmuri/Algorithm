#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int lost_point[100'000'001];

int main(){
    FASTIO

    int n;
    cin >> n;

    set<int> exists;
    vector<int> cards(n);
    int max_card = 0;
    for(int i = 0; i < n; i++){
        cin >> cards[i];
        exists.insert(cards[i]);
        max_card = max(max_card, cards[i]);
    }

    vector<int> answer(n, 0);
    for(int c = 0; c < n; c++){
        for(int i = cards[c] * 2; i <= max_card; i += cards[c]){
            lost_point[i]--;
            if(exists.find(i) != exists.end()) answer[c]++;
        }
    }

    for(int i = 0; i < n; i++){
        answer[i] += lost_point[cards[i]];
    }

    for(int ans : answer) cout << ans << " ";

    return 0;
}