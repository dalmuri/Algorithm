#include <string>
#include <vector>
#include <queue>

using namespace std;
int inf = 60'000'001;

struct cmp{
  bool operator()(pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
  }  
};

vector<int> dijkstra(int start, int n, vector<vector<vector<int>>>& cost){
    vector<int> dist(n + 1, inf);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // idx, distance
    pq.push(make_pair(start, 0));
    
    while(!pq.empty()){
        int now_idx = pq.top().first;
        int now_dist = pq.top().second;
        pq.pop();
        
        if(dist[now_idx] < now_dist) continue;
        
        for(vector<int> next : cost[now_idx]){
            int next_idx = next[0];
            int next_dist = now_dist + next[1];
            
            if(next_dist < dist[next_idx]){
                dist[next_idx] = next_dist;
                pq.push(make_pair(next_idx, next_dist));
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<vector<int>>> cost(n + 1, vector<vector<int>>());
    for(vector<int> fare : fares){
        cost[fare[0]].push_back({fare[1], fare[2]});
        cost[fare[1]].push_back({fare[0], fare[2]});
    }
    
    vector<int> dist_s = dijkstra(s, n, cost);
    vector<int> dist_a = dijkstra(a, n, cost);
    vector<int> dist_b = dijkstra(b, n, cost);
    
    int answer = inf;
    for(int i = 1; i <= n; i++){
        answer = min(answer, dist_s[i] + dist_a[i] + dist_b[i]);
    }
    return answer;
}