#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int min_price = 1'000'000'001;
    int max_profit = 0;
    for(int i = 0; i < n; ++i){
        int price;
        cin >> price;

        min_price = min(min_price, price);
        max_profit = max(max_profit, price - min_price);
    }

    cout << max_profit;

    return 0;
}