#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> w(10);
    vector<int> k(10);

    for(int i = 0; i < 10; i++) cin >> w[i];
    for(int i = 0; i < 10; i++) cin >> k[i];

    sort(w.rbegin(), w.rend());
    sort(k.rbegin(), k.rend());

    cout << accumulate(w.begin(), w.begin() + 3, 0) << " " << accumulate(k.begin(), k.begin() + 3, 0);

    return 0;
}