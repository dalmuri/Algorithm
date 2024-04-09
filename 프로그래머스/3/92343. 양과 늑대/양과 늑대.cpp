#include <string>
#include <vector>

using namespace std;

int search(int now, int sheep, int wolf, vector<bool> visited, vector<int>& info, vector<vector<int>>& edges){
    if(wolf >= sheep) return sheep;
    
    int result = sheep;
    for(vector<int> edge : edges){
        int parent = edge[0];
        int child = edge[1];
        
        if(visited[parent] && !visited[child]){
            visited[child] = true;
            
            if(info[child] == 0) result = max(result, search(child, sheep + 1, wolf, visited, info, edges));
            else result = max(result, search(child, sheep, wolf + 1, visited, info, edges));
            
            visited[child] = false;
        }
    }
    
    return result;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<bool> visited(info.size(), false);
    visited[0] = true;
    
    return search(0, 1, 0, visited, info, edges);
}