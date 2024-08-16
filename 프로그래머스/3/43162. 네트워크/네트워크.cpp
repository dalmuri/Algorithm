#include <string>
#include <vector>

using namespace std;

void dfs(int com, int n, vector<vector<int>>& computers, vector<bool>& visited){
    visited[com] = true;
    for(int i = 0; i < n; i++){
        if(computers[com][i] && !visited[i]) dfs(i, n, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, n, computers, visited);
            answer++;
        }
    }
    return answer;
}