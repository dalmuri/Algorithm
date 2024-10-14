#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void dfs(int node, vector<bool>& visited, vector<set<int>>& edges){
    if(visited[node]) return;

    visited[node] = true;
    cout << node << " ";

    for(auto iter = edges[node].begin(); iter != edges[node].end(); iter++){
        dfs((*iter), visited, edges);
    }
}

void bfs(int start, vector<set<int>>& edges){
    vector<bool> visited(edges.size(), false);
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(visited[node]) continue;

        visited[node] = true;
        cout << node << " ";

        for(auto iter = edges[node].begin(); iter != edges[node].end(); iter++){
            q.push(*iter);
        }
    }
}

int main(){
    FASTIO

    int n, m, v;
    cin >> n >> m >> v;

    vector<set<int>> edges(n + 1, set<int>());

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    
    vector<bool> visited(n + 1, false);
    dfs(v, visited, edges);

    cout << "\n";

    bfs(v, edges);

    return 0;
}