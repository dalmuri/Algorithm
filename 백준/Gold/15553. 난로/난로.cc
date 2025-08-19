#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k, prev;
    cin >> n >> k >> prev;

    vector<int> delay(n - 1);
    for(int i = 0, now; i < n - 1; ++i){
        cin >> now;
        delay[i] = now - prev - 1;

        prev = now;
    }

    sort(delay.begin(), delay.end());

    cout << accumulate(delay.begin(), delay.begin() + n - k, 0) + n;

    return 0;
}