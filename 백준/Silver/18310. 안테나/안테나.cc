#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> houses(n);
    for(int i = 0; i < n; i++) cin >> houses[i];

    sort(houses.begin(), houses.end());

    cout << houses[(n - 1) / 2];

    return 0;
}