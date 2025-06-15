#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, l, p;
    cin >> n;

    vector<pair<int, int>> stations(n);
    for(int i = 0; i < n; ++i) cin >> stations[i].second >> stations[i].first;
    cin >> l >> p;

    sort(stations.begin(), stations.end(), [](pair<int, int> a, pair<int, int> b){ return a.second < b.second; });

    int now = p, answer = 0, idx = 0;
    priority_queue<pair<int, int>> pq;
    while(now < l){
        for(; idx < n && stations[idx].second <= now; ++idx) pq.push(stations[idx]);

        if(pq.empty()){
            answer = -1;
            break;
        }

        answer++;
        now += pq.top().first;
        pq.pop();
    }

    cout << answer;

    return 0;
}