#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct delivery{
    int from, to, box;

    bool operator<(const delivery& other) const {
        if(to != other.to) return to < other.to;
        return from < other.from;
    }

    bool operator>(const delivery& other) const {
        if(to != other.to) return to > other.to;
        return from > other.from;
    }
};

int main(){
    FASTIO

    int n, c, m;
    cin >> n >> c >> m;

    vector<delivery> deliveries(m);
    for(int i = 0; i < m; i++){
        cin >> deliveries[i].from >> deliveries[i].to >> deliveries[i].box;
    }

    sort(deliveries.begin(), deliveries.end());

    int box = 0, answer = 0;
    priority_queue<delivery, vector<delivery>, greater<delivery>> pq;

    for(int i = 0; i < m; i++){
        while(!pq.empty() && pq.top().to <= deliveries[i].from){
            box -= pq.top().box;
            pq.pop();
        }

        int plus = min(c - box, deliveries[i].box);
        if(plus > 0){
            pq.push({deliveries[i].from, deliveries[i].to, plus});
            box += plus;
            answer += plus;
        }
    }

    cout << answer;

    return 0;
}