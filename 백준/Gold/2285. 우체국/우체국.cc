#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> towns(n);
    for(int i = 0; i < n; ++i) cin >> towns[i].first >> towns[i].second;

    sort(towns.begin(), towns.end());

    int l = 0, r = n - 1;
    long long l_sum = towns[0].second, r_sum = towns.back().second;
    while(l < r){
        if(l_sum < r_sum) l_sum += towns[++l].second;
        else r_sum += towns[--r].second;
    }

    cout << towns[l].first;

    return 0;
}