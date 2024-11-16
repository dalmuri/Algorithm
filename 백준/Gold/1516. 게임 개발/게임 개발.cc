#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> indegree(n + 1);
    vector<vector<int>> outs(n + 1);
    vector<int> costs(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> costs[i];

        while(1){
            int num;
            cin >> num;
            if(num == -1) break;

            indegree[i]++;
            outs[num].push_back(i);
        }
    }

    queue<int> q;
    vector<int> answer(n + 1);
    for(int i = 1; i <= n; i++){
        answer[i] = costs[i];
        if(indegree[i] == 0) q.push(i);
    }

    
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int next : outs[now]){
            indegree[next]--;
            answer[next] = max(answer[next], answer[now] + costs[next]);

            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << answer[i] << "\n";

    return 0;
}