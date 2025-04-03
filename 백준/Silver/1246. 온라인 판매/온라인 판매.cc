#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> prices(m);
    for(int i = 0; i < m; ++i) cin >> prices[i];

    sort(prices.rbegin(), prices.rend());

    int max_price = 0, max_profit = 0;
    for(int i = 0; i < min(n, m); ++i){
        int profit = prices[i] * (i + 1);
        if(profit > max_profit){
            max_profit = profit;
            max_price = prices[i];
        }
    }

    cout << max_price << " " << max_profit;

    return 0;
}