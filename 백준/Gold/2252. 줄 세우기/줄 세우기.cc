#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<vector<int>> seq;
vector<int> indegree;

void topology_sort(){
    queue<int> q;
    for(int i = 1; i <= n; i++) if(indegree[i] == 0) q.push(i);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        cout << now << " ";
        for(int next : seq[now]){
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
}

int main(){
    FASTIO

    int m;
    cin >> n >> m;

    seq = vector<vector<int>>(n + 1);
    indegree = vector<int>(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        seq[a].push_back(b);
        indegree[b]++;
    }

    topology_sort();

    return 0;
}