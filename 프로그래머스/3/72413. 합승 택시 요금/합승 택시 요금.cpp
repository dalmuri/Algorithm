#include <string>
#include <vector>
#include <queue>

using namespace std;

int inf = 60'000'001;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

vector<int> dijkstra(int start, int n, vector<vector<vector<int>>>& costs){
    vector<int> dist(n + 1, inf);
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    while(!pq.empty()){
        int now = pq.top().first;
        int now_dist = pq.top().second;
        pq.pop();
        
        if(now_dist > dist[now]) continue;
        for(vector<int> cost : costs[now]){
            int next = cost[0];
            int next_dist = now_dist + cost[1];
            
            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next, next_dist});
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<vector<int>>> costs(n + 1, vector<vector<int>>());
    for(vector<int> fare : fares){
        costs[fare[0]].push_back({fare[1], fare[2]});
        costs[fare[1]].push_back({fare[0], fare[2]});
    }
    
    vector<int> from_s = dijkstra(s, n, costs);
    vector<int> to_a = dijkstra(a, n, costs);
    vector<int> to_b = dijkstra(b, n, costs);
    
    int answer = inf;
    for(int i = 1; i <= n; i++){
        answer = min(answer, from_s[i] + to_a[i] + to_b[i]);
    }
    return answer;
}