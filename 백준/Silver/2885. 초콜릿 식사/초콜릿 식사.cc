#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int k;
    cin >> k;

    int bit = 1, small_bit = 0, cnt = 1;
    for(; bit < k; bit <<= 1, ++cnt){
        if(small_bit == 0 && (bit & k)) small_bit = cnt;
    }

    cout << bit << " " << (small_bit > 0 ? cnt - small_bit : 0);

    return 0;
}