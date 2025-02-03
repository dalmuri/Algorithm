#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int coins[6] = {500, 100, 50, 10, 5, 1};

int main(){
    FASTIO

    int n;
    cin >> n;
    
    int money = 1000 - n;
    int answer = 0;
    
    for(int coin : coins){
        answer += money / coin;
        money %= coin;
    }
    
    cout << answer;

    return 0;
}