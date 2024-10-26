#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> indegree;
vector<set<int>> graph;

void topology_sort(int n, vector<int>& answer){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        answer.push_back(now);

        for(int next : graph[now]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    indegree = vector<int>(n + 1, 0);
    graph = vector<set<int>>(n + 1);

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        vector<int> seq(k);
        for(int j = 0; j < k; j++) cin >> seq[j];

        for(int j = 0; j + 1 < k; j++){
            graph[seq[j]].insert(seq[j + 1]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(auto iter = graph[i].begin(); iter != graph[i].end(); iter++){
            indegree[*iter]++;
        }
    }

    vector<int> answer;
    topology_sort(n, answer);

    if(answer.size() < n) cout << 0;
    else{
        for(int node : answer) cout << node << "\n";
    }

    return 0;
}