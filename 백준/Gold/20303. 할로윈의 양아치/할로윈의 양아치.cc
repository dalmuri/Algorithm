#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> candy;
vector<vector<int>> friends;
vector<bool> visited;

pair<int, int> search(int node){
    visited[node] = true;
    pair<int, int> res = {candy[node], 1};
    for(int f : friends[node]){
        if(visited[f]) continue;

        pair<int, int> tmp = search(f);
        res.first += tmp.first;
        res.second += tmp.second;
    }

    return res;
}

int main(){
    FASTIO

    int n, m, k;
    cin >> n >> m >> k;

    candy = vector<int>(n + 1);
    for(int i = 1; i <= n; i++) cin >> candy[i];

    friends = vector<vector<int>>(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    visited = vector<bool>(n + 1, false);
    vector<pair<int, int>> infos; // {사탕 수, 사람 수}
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;

        infos.push_back(search(i));
    }

    vector<int> dp(k, 0); // dp[i] = i명을 울렸을 때 얻을 수 있는 사탕의 최댓값
    int answer = 0;
    for(pair<int, int> info : infos){
        int c = info.first;
        int f = info.second;

        for(int i = k - f - 1; i >= 0; i--){
            dp[i + f] = max(dp[i + f], dp[i] + c);
            answer = max(answer, dp[i + f]);
        }
    }

    cout << answer;

    return 0;
}