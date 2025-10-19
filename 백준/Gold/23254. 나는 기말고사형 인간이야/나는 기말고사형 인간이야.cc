#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    int time = n * 24;
    vector<pair<int, int>> subjects(m); // (1시간 공부할 때 올릴 수 있는 점수, 현재 점수)
    for(int i = 0; i < m; ++i) cin >> subjects[i].second;
    for(int i = 0; i < m; ++i) cin >> subjects[i].first;

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < m; ++i) pq.push(subjects[i]);

    int answer = 0;
    while(!pq.empty() && time > 0){
        auto [delta, now] = pq.top();
        pq.pop();

        int study_time = min(time, (100 - now) / delta);
        time -= study_time;
        now += delta * study_time;
        if(now < 100) pq.push({100 - now, now});
        else answer += 100;
    }

    while(!pq.empty()){
        answer += pq.top().second;
        pq.pop();
    }

    cout << answer;
    
    return 0;
}