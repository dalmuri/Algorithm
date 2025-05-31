#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

long long n;
vector<long long> fac(1, 1ll);
bool can_add(long long now, int idx){
    if(now > n) return false;
    if(now == n) return true;
    if(idx < 0) return false;
    return can_add(now + fac[idx], idx - 1) || can_add(now, idx - 1);
}

int main(){
    FASTIO
    
    cin >> n;

    for(int i = 1; 1; ++i){
        long long next = fac[i - 1] * i;
        if(next > n) break;
        fac.push_back(next);
    }

    cout << (n > 0ll && can_add(0ll, fac.size() - 1) ? "YES" : "NO");

    return 0;
}