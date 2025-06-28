#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> works(n);
    for(int i = 0; i < n; ++i) cin >> works[i].second >> works[i].first;

    sort(works.rbegin(), works.rend());

    int start = works[0].first + 1;
    for(int i = 0; i < n; ++i){
        start = min(start, works[i].first + 1) - works[i].second;
    }

    cout << start - 1;

    return 0;
}