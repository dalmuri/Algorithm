#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    unordered_map<long long, int> cards;
    long long max_card = 0;
    int max_cnt = 0;
    for(int i = 0; i < n; i++){
        long long card;
        cin >> card;

        int cnt = ++cards[card];
        if(max_cnt < cnt || (max_cnt == cnt && card < max_card)){
            max_cnt = cnt;
            max_card = card;
        }
    }

    cout << max_card;

    return 0;
}