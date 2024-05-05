#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int get_dist(int source, int dest, int n, vector<vector<vector<int>>>& graph){
    queue<vector<int>> q;
    q.push({source, 0}); // node, distance
    vector<bool> visited(n + 1, false);
    visited[source] = true;

    int result = -1;
    while(!q.empty()){
        int now = q.front()[0];
        int dist = q.front()[1];
        q.pop();

        if(now == dest){
            result = dist;
            break;
        }

        for(vector<int> next : graph[now]){
            if(visited[next[0]]) continue;

            visited[next[0]] = true;
            q.push({next[0], dist + next[1]});
        }
    }

    return result;
}

int main() {
    FASTIO;
    
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> graph(n + 1, vector<vector<int>>());
    for(int i = 0; i < n - 1; i++){
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << get_dist(a, b, n, graph) << "\n";
    }
    
    return 0;
}