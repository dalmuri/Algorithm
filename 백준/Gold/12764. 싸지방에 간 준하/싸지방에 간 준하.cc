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
    map<int, int> computers; // (자리 번호, 사용한 사람 수)
    for(int i = 0, num; i < n; ++i){
        while(!pq_using.empty() && pq_using.top().first < times[i].first){
            pq_empty.push(pq_using.top().second);
            pq_using.pop();
        }
        if(pq_empty.empty()) num = computers.size();
        else{
            num = pq_empty.top();
            pq_empty.pop();
        }

        computers[num]++;
        pq_using.push({times[i].second, num});
    }

    cout << computers.size() << "\n";
    for(auto iter = computers.begin(); iter != computers.end(); ++iter) cout << iter->second << " ";

    return 0;
}