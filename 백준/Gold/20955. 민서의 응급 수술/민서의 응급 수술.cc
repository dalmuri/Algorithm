#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int cnt_disconnect(int node, int parent, vector<vector<int>>& neurons, vector<bool>& visited){
    int cnt = 0;
    visited[node] = true;

    for(int child : neurons[node]){
        if(child == parent) continue;

        if(visited[child]) ++cnt;
        else cnt += cnt_disconnect(child, node, neurons, visited);
    }

    return cnt;
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<vector<int>> neurons(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        neurons[u].push_back(v);
        neurons[v].push_back(u);
    }

    vector<bool> visited(n + 1);
    int to_disconnect = 0;
    int to_connect = -1;
    for(int i = 1; i <= n; ++i){
        if(visited[i]) continue;

        ++to_connect;
        to_disconnect += cnt_disconnect(i, -1, neurons, visited) / 2;
    }

    cout << to_disconnect + to_connect;

    return 0;
}