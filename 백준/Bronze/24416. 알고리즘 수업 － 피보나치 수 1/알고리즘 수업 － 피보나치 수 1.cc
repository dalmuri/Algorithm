#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> cnt(n + 1, 1);
    for(int i = 3; i <= n; i++) cnt[i] = cnt[i - 1] + cnt[i - 2];

    cout << cnt[n] << " " << n - 2;

    return 0;
}