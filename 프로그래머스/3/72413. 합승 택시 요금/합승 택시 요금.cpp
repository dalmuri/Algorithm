#include <string>
#include <vector>
#include <queue>

using namespace std;
int inf = 87654321;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

vector<int> dijkstra(int start, int n, vector<vector<vector<int>>>& roads){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // {next, next_dist}
    vector<int> dist(n + 1, inf);
    dist[start] = 0;
    pq.push({start, 0});
    
    while(!pq.empty()){
        int now = pq.top().first;
        int now_dist = pq.top().second;
        pq.pop();
        
        if(now_dist > dist[now]) continue;
        for(vector<int> road : roads[now]){
            int next = road[0];
            int next_dist = now_dist + road[1];
            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next, next_dist});
            }
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<vector<int>>> roads(n + 1, vector<vector<int>>());
    for(vector<int> fare : fares){
        roads[fare[0]].push_back({fare[1], fare[2]});
        roads[fare[1]].push_back({fare[0], fare[2]});
    }
    
    vector<int> dist_s = dijkstra(s, n, roads);
    vector<int> dist_a = dijkstra(a, n, roads);
    vector<int> dist_b = dijkstra(b, n, roads);
    
    int answer = inf;
    for(int i = 1; i <= n; i++){
        answer = min(answer, dist_s[i] + dist_a[i] + dist_b[i]);
    }
    return answer;
}