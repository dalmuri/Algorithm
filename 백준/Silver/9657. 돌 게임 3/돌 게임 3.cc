#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<bool> can_win(n + 1, false);
    can_win[1] = true;
    if(n >= 3) can_win[3] = true;
    if(n >= 4) can_win[4] = true;
    for(int i = 5; i <= n; i++){
        can_win[i] = !(can_win[i - 1] && can_win[i - 3] && can_win[i - 4]);
    }

    cout << (can_win[n] ? "SK" : "CY");

    return 0;
}