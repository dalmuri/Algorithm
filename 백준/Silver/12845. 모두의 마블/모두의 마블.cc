#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> cards(n);
    for(int i = 0; i < n; ++i) cin >> cards[i];

    cout << accumulate(cards.begin(), cards.end(), 0) + *max_element(cards.begin(), cards.end()) * (n - 2);

    return 0;
}