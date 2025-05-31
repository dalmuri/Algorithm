#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO
    
    long long n;
    cin >> n;
    if(n == 0ll) n = -1ll;

    vector<long long> fac(1, 1ll);
    for(int i = 1; 1; ++i){
        long long next = fac[i - 1] * i;
        if(next > n) break;
        fac.push_back(next);
    }

    for(int i = fac.size() - 1; i >= 0; --i){
        if(n >= fac[i]) n -= fac[i];
    }

    cout << (n == 0 ? "YES" : "NO");

    return 0;
}