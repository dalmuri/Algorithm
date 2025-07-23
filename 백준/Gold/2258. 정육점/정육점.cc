#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    using pii = pair<int, int>;

    int n, m;
    cin >> n >> m;

    vector<pii> meats(n); // (가격, 무게)
    for(int i = 0; i < n; ++i) cin >> meats[i].second >> meats[i].first;

    sort(meats.begin(), meats.end(), [](pii a, pii b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    int answer = -1;
    for(int i = 0, now_cnt = 0, weight = 0; i < n; ++i){
        weight += meats[i].second;
        if(i == 0 || meats[i - 1].first == meats[i].first) now_cnt++;
        else now_cnt = 1;

        if(weight >= m && (answer == -1 || answer > meats[i].first * now_cnt)) answer = meats[i].first * now_cnt;
    }

    cout << answer;

    return 0;
}