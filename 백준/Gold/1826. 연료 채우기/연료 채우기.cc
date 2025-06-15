#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, l, p;
    cin >> n;

    vector<pair<int, int>> stations(n);
    for(int i = 0; i < n; ++i) cin >> stations[i].first >> stations[i].second;
    cin >> l >> p;

    sort(stations.begin(), stations.end());

    int now = p, answer = 0, idx = 0;
    priority_queue<int> pq;
    while(now < l){
        for(; idx < n && stations[idx].first <= now; ++idx) pq.push(stations[idx].second);

        if(pq.empty()){
            answer = -1;
            break;
        }

        answer++;
        now += pq.top();
        pq.pop();
    }

    cout << answer;

    return 0;
}