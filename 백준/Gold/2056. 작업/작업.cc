#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> times(n + 1);
    vector<int> indegree(n + 1);
    vector<vector<int>> next_works(n + 1);
    queue<int> q;

    for(int i = 1; i <= n; i++){
        int time, cnt;
        cin >> time >> cnt;

        times[i] = time;
        indegree[i] = cnt;
        if(cnt == 0) q.push(i);
        for(int j = 0; j < cnt; j++){
            int work;
            cin >> work;

            next_works[work].push_back(i);
        }
    }

    vector<int> dp(n + 1, 0); // dp[i] = i 작업을 끝내는데 걸리는 시간의 최솟값
    int answer = 0;
    while(!q.empty()){
        int work = q.front();
        q.pop();

        dp[work] += times[work];
        answer = max(answer, dp[work]);

        for(int next : next_works[work]){
            dp[next] = max(dp[next], dp[work]);
            indegree[next]--;

            if(indegree[next] == 0) q.push(next);
        }
    }

    cout << answer;

    return 0;
}