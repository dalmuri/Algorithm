#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<long long> bit_count(64, 0); // bit_count[i] = (1<<i)보다 작은 수들의 1의 개수

long long count(long long num){
    long long res = 0ll;
    for(int i = 63; i >= 0; i--){
        if(num & (1ll << i)){
            res += bit_count[i] + num - (1ll << i) + 1;
            num -= 1ll << i;
        }
    }

    return res;
}

int main(){
    FASTIO

    long long a, b;
    cin >> a >> b;

    for(int i = 1; i < 64; i++){
        bit_count[i] = (bit_count[i - 1] << 1) + (1ll << (i - 1));
    }

    cout << count(b) - count(a - 1);

    return 0;
}