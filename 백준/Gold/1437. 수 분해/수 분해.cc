#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int mod = 10'007;

    int n, answer = 1;
    cin >> n;

    for(; n > 4; n -= 3) answer = (answer * 3) % mod;
    answer = (answer * n) % mod;

    cout << answer;

    return 0;
}