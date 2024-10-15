#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int inf = 123456789;
struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

vector<int> dijkstra(int start, int n, vector<vector<vector<int>>>& roads){
    vector<int> dist(n + 1, inf);
    dist[start] = 0;

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({start, 0});

    while(!pq.empty()){
        int now = pq.top()[0];
        int now_dist = pq.top()[1];
        pq.pop();

        if(dist[now] < now_dist) continue;

        for(vector<int> road : roads[now]){
            int next = road[0];
            int next_dist = now_dist + road[1];

            if(dist[next] > next_dist){
                dist[next] = next_dist;
                pq.push({next, next_dist});
            }
        }
    }

    return dist;
}

int main(){
    FASTIO

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<vector<int>>> roads1(n + 1, vector<vector<int>>());
    vector<vector<vector<int>>> roads2(n + 1, vector<vector<int>>());
    for(int i = 0; i < m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        roads1[a].push_back({b, t});
        roads2[b].push_back({a, t});
    }

    vector<int> dist1 = dijkstra(x, n, roads1);
    vector<int> dist2 = dijkstra(x, n, roads2);

    int max_dist = dist1[1] + dist2[1];
    for(int i = 2; i <= n; i++){
        max_dist = max(max_dist, dist1[i] + dist2[i]);
    }

    cout << max_dist;

    return 0;
}