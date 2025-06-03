#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    long long n;
    cin >> n;

    if(n == 0ll) cout << "0";
    else{
        int answer = 1;
        for(long long bit = 1ll; bit < n; ++answer, bit <<= 1);

        cout << answer;
    }

    return 0;
}