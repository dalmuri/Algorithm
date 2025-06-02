#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    long long w;
    cin >> n >> w;

    vector<int> prices(n);
    for(int i = 0; i < n; ++i) cin >> prices[i];

    long long coin = 0ll;
    for(int i = 0; i + 1 < n; ++i){
        if(prices[i] <= prices[i + 1]){
            coin += w / prices[i];
            w %= prices[i];
        }
        else{
            w += coin * prices[i];
            coin = 0ll;
        }
    }

    w += coin * prices.back();

    cout << w;

    return 0;
}