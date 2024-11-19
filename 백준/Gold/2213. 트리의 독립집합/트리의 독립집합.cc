#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> edges[10'001];
bool visited[10'001];
int dp[10'001][2];

int calc(int node, int parent){
    visited[node] = true;
    
    for(int child : edges[node]){
        if(child == parent) continue;
        if(!visited[child]) calc(child, node);

        dp[node][0] += max(dp[child][0], dp[child][1]);
        dp[node][1] += dp[child][0];
    }

    return max(dp[node][0], dp[node][1]);
}

void trace_path(int node, int parent){
    if(!visited[parent] && dp[node][0] < dp[node][1]) visited[node] = true;

    for(int child : edges[node]){
        if(child == parent) continue;
        
        trace_path(child, node);
    }
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> dp[i][1];
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout << calc(1, 0) << "\n";
    
    memset(visited + 1, false, sizeof(bool) * n);
    trace_path(1, 0);
    for(int i = 1; i <= n; i++){
        if(visited[i]) cout << i << " ";
    }

    return 0;
}