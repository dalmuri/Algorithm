#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    using pii = pair<int, int>;
    const int inf = 2'147'483'647;

    int n, m;
    cin >> n >> m;

    vector<pii> meats(n); // (가격, 무게)
    for(int i = 0; i < n; ++i) cin >> meats[i].second >> meats[i].first;

    sort(meats.begin(), meats.end(), [](pii a, pii b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    int answer = -1;
    pii last = {0, 0}, now = {0, 0};
    for(int i = 0, now_cnt = 0; i < n; ++i){
        if(now.first < meats[i].first){
            last = {meats[i].first, last.second + now.second};
            now = meats[i];
            now_cnt = 1;

            if(last.second + meats[i].second >= m && (answer == -1 || answer > meats[i].first)) answer = meats[i].first;
        }
        else{
            now.second += meats[i].second;
            now_cnt++;

            if(last.second + now.second >= m && (answer == -1 || answer > now.first * now_cnt)) answer = now.first * now_cnt;
        }
    }

    cout << answer;

    return 0;
}