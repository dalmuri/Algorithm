#include <vector>
#include <algorithm>

using namespace std;

int get_parent(int node, vector<int>& parent){
    if(parent[node] == -1) return node;
    return get_parent(parent[node], parent);
}

int solution(int n, vector<vector<int>> costs) {
    vector<int> parent(n, -1);
    
    int answer = 0;
    int cnt = 0;
    sort(costs.begin(), costs.end(), [](auto a, auto b){ return a[2] < b[2]; });
    for(vector<int> cost : costs){
        int p1 = get_parent(cost[0], parent);
        int p2 = get_parent(cost[1], parent);
        
        if(p1 != p2){
            cnt++;
            answer += cost[2];
            parent[p2] = p1;
            
            if(cnt == n - 1) break;
        }
    }
    
    return answer;
}