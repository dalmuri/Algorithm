#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0, coin; i < n * 2; ++i){
        cin >> coin;
        sum += abs(coin);
    }

    cout << sum;

    return 0;
}