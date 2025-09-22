#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> dishes(n);
    for(int i = 0; i < n; ++i) cin >> dishes[i];

    sort(dishes.begin(), dishes.end());

    cout << accumulate(dishes.begin(), dishes.begin() + n / 2, 0) << " " << accumulate(dishes.begin() + n / 2, dishes.end(), 0);

    return 0;
}