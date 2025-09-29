#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> soldiers(n);
    for(int i = 0; i < n; ++i) cin >> soldiers[i].first;
    for(int i = 0; i < n - 1; ++i) cin >> soldiers[i].second;

    int now = 0;
    for(int i = 0; i < n; ++i){
        if(now < soldiers[i].first) break;
        now = max(now, soldiers[i].first + soldiers[i].second);
    }

    if(now < soldiers.back().first) cout << "엄마 나 전역 늦어질 것 같아";
    else cout << "권병장님, 중대장님이 찾으십니다";

    return 0;
}