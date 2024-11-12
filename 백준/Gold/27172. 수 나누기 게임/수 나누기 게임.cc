#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int score[1'000'001];
bool exists[1'000'001];

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> cards(n);
    int max_card = 0;
    for(int i = 0; i < n; i++){
        cin >> cards[i];
        exists[cards[i]] = true;
        max_card = max(max_card, cards[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = cards[i] * 2; j <= max_card; j += cards[i]){
            if(exists[j]){
                score[j]--;
                score[cards[i]]++;
            }
        }
    }

    for(int card : cards) cout << score[card] << " ";

    return 0;
}