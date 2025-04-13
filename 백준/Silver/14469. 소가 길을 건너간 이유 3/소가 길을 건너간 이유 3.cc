#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> cows(n);
    for(int i = 0; i < n; ++i) cin >> cows[i].first >> cows[i].second;

    sort(cows.begin(), cows.end());

    int last = 0;
    for(int i = 0; i < n; ++i){
        last = max(last, cows[i].first) + cows[i].second;
    }

    cout << last;

    return 0;
}