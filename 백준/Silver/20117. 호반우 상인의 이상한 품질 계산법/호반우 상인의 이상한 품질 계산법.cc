#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> qualities(n);
    for(int i = 0; i < n; ++i) cin >> qualities[i];

    sort(qualities.begin(), qualities.end());

    int sum = accumulate(qualities.begin() + n / 2, qualities.end(), 0) * 2;
    if(n & 1) sum -= qualities[n / 2];

    cout << sum;

    return 0;
}