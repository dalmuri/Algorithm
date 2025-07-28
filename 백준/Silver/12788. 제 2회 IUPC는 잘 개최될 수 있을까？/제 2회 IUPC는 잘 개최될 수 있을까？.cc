#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> pens(n);
    for(int i = 0; i < n; ++i) cin >> pens[i];

    sort(pens.rbegin(), pens.rend());

    int idx = 0;
    for(int sum = 0; idx < n; ++idx){
        sum += pens[idx];
        if(sum >= m * k) break;
    }

    if(idx >= n) cout << "STRESS";
    else cout << idx + 1;

    return 0;
}