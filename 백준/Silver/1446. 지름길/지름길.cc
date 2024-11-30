#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int n, d;
    cin >> n >> d;

    using tri = tuple<int, int, int>;
    priority_queue<tri, vector<tri>, greater<tri>> pq;
    for(int i = 0; i < n; i++){
        int start, end, dist;
        cin >> start >> end >> dist;

        pq.push({start, end, dist});
    }

    vector<int> road(d + 1, inf);
    road[0] = 0;
    for(int i = 0; i < d; i++){
        road[i + 1] = min(road[i + 1], road[i] + 1);

        while(!pq.empty() && get<0>(pq.top()) == i){
            auto [start, end, dist] = pq.top();
            pq.pop();

            if(end > d) continue;
            road[end] = min(road[end], road[start] + dist);
        }
    }

    cout << road[d];

    return 0;
}