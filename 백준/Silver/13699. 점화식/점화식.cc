#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<long long> t(n + 1, 0ll);
    t[0] = 1ll;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            t[i] += t[j] * t[i - 1 - j];
        }
    }

    cout << t[n];

    return 0;
}