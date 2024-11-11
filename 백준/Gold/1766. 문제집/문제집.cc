#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        indegree[b]++;
        graph[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int now = pq.top();
        pq.pop();

        cout << now << " ";
        for(int next : graph[now]){
            indegree[next]--;

            if(indegree[next] == 0) pq.push(next);
        }
    }

    return 0;
}