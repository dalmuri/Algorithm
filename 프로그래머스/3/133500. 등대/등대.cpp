#include <vector>

using namespace std;

int turn_on(int node, int parent, vector<bool>& lighted, vector<vector<int>>& road){
    int result = 0;
    for(int child : road[node]){
        if(child == parent) continue;
        
        result += turn_on(child, node, lighted, road);
        
        if(!lighted[child] && !lighted[node]){
            lighted[node] = true;
            result++;
        }
    }
    return result;
}

int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> road(n + 1, vector<int>());
    for(vector<int> edge : lighthouse){
        road[edge[0]].push_back(edge[1]);
        road[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> lighted(n + 1, false);
    
    return turn_on(1, -1, lighted, road);
}