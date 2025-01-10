#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;

    set<int> cards;
    for(int i = 0; i < n; i++){
        int card;
        cin >> card;

        cards.insert(card);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int number;
        cin >> number;

        cout << cards.count(number) << " ";
    }

    return 0;
}