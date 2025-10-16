#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    long long m, time;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> time;
        m -= time - 1;
    }

    cout << (m > 0 ? "OUT" : "DIMI");

    return 0;
}