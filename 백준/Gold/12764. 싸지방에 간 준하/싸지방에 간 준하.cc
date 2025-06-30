#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    using pii = pair<int, int>;

    int n;
    cin >> n;

    vector<pii> times(n);
    for(int i = 0; i < n; ++i) cin >> times[i].first >> times[i].second;

    sort(times.begin(), times.end());

    priority_queue<pii, vector<pii>, greater<pii>> pq_using; // (종료 시각, 자리 번호)
    priority_queue<int, vector<int>, greater<int>> pq_empty; // 빈 자리 번호
    vector<int> cnt(n, 0);
    int answer = 0;
    for(int i = 0, num; i < n; ++i){
        while(!pq_using.empty() && pq_using.top().first < times[i].first){
            pq_empty.push(pq_using.top().second);
            pq_using.pop();
        }

        if(pq_empty.empty()){
            num = pq_using.size();
            answer++;
        }
        else{
            num = pq_empty.top();
            pq_empty.pop();
        }

        cnt[num]++;
        pq_using.push({times[i].second, num});
    }

    cout << answer << "\n";
    for(int i = 0; i < answer; ++i) cout << cnt[i] << " ";

    return 0;
}