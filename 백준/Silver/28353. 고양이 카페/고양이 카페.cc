#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> weights(n);
    for(int i = 0; i < n; ++i) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int l = 0, r = n - 1;
    while(l < r){
        if(weights[l] + weights[r] <= k) l++;
        r--;
    }

    cout << l;

    return 0;
}