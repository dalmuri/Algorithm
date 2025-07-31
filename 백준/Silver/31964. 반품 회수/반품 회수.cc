#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> homes(n);
    for(int i = 0; i < n; ++i) cin >> homes[i].first;
    for(int i = 0; i < n; ++i) cin >> homes[i].second;

    sort(homes.begin(), homes.end());

    int now = max(homes.back().first, homes.back().second);
    for(int i = n - 2; i >= 0; --i){
        now = max(now + homes[i + 1].first - homes[i].first, homes[i].second);
    }

    cout << now + homes.front().first;

    return 0;
}