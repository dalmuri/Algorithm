#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void dfs(int node, int& order, vector<vector<int>>& edges, const int& n, vector<bool>& visited, vector<int>& answer){
    if(visited[node]) return;
    visited[node] = true;

    answer[node] = order++;
    for(int next : edges[node]){
        dfs(next, order, edges, n, visited, answer);
    }
}

int main(){
    FASTIO

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> edges(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) sort(edges[i].begin(), edges[i].end());

    int order = 1;
    vector<bool> visited(n + 1, false);
    vector<int> answer(n + 1, 0);

    dfs(r, order, edges, n, visited, answer);

    for(int i = 1; i <= n; i++) cout << answer[i] << "\n";

    return 0;
}