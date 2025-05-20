#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> meetings(n);
    for(int i = 0; i < n; ++i) cin >> meetings[i].first >> meetings[i].second;

    sort(meetings.begin(), meetings.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    for(int i = 0; i < n; ++i){
        if(!pq.empty() && pq.top() <= meetings[i].first){
            pq.pop();
        }

        pq.push(meetings[i].second);
        answer = max(answer, (int)pq.size());
    }

    cout << answer;

    return 0;
}