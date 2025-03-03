#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

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

    for(int i = 1; i <= n; i++) sort(edges[i].rbegin(), edges[i].rend());

    queue<int> q;
    q.push(r);

    int ord = 1;
    vector<int> orders(n + 1, 0);
    orders[r] = ord;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int next : edges[now]){
            if(orders[next]) continue;
            q.push(next);
            orders[next] = ++ord;
        }
    }

    for(int i = 1; i <= n; i++) cout << orders[i] << "\n";

    return 0;
}