#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    } 
};

void search(int start, int n, vector<int>& types, vector<vector<vector<int>>>& costs, vector<int>& answer){
    // Dijkstra
    vector<int> intensities(n + 1, INT_MAX);
    intensities[start] = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; // {idx, intensity}
    pq.push({start, 0});
    
    while(!pq.empty()){
        int now = pq.top()[0];
        int now_intensity = pq.top()[1];
        pq.pop();
        
        if(types[now] == 2){
            if(now_intensity < answer[1] || (now_intensity == answer[1] && now < answer[0])){
                answer[0] = now;
                answer[1] = now_intensity;
            }
            return;
        }
        
        if(now_intensity > intensities[now]) continue;
        for(vector<int> cost : costs[now]){
            int next = cost[0];
            int next_intensity = max(now_intensity, cost[1]);
            if(types[next] == 1) continue;
            
            if(next_intensity < intensities[next]){
                intensities[next] = next_intensity;
                pq.push({next, next_intensity});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer = {-1, INT_MAX};
    
    // 각 지점의 타입 설정
    vector<int> types(n + 1, 0); // 0: 쉼터, 1: 출입구, 2: 산봉우리
    for(int gate : gates) types[gate] = 1;
    for(int summit : summits) types[summit] = 2;
    
    // 모든 경로의 cost 설정
    vector<vector<vector<int>>> costs(n + 1, vector<vector<int>>());
    for(vector<int> path : paths){
        costs[path[0]].push_back({path[1], path[2]});
        costs[path[1]].push_back({path[0], path[2]});
    }
    
    // 모든 출발지점으로부터 계산
    for(int gate : gates){
        search(gate, n, types, costs, answer);
    }
    
    return answer;
}