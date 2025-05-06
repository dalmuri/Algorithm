#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i) a[i].first = i;

    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y){ return x.second < y.second; });

    for(int i = 0; i < n; ++i) cout << a[i].first << " ";

    return 0;
}