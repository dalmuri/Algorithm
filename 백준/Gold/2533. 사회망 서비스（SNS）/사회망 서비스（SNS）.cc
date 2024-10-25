#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<int>> tree;
vector<bool> is_early;

int count_no_ealry_friends(int node, int parent){
    int cnt = 0;
    for(int child : tree[node]){
        if(child == parent) continue;

        cnt += count_no_ealry_friends(child, node);
    }

    if(cnt){
        is_early[node] = true;
        return 0;
    }
    return 1;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    tree = vector<vector<int>>(n + 1, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    is_early = vector<bool>(n + 1, false);

    count_no_ealry_friends(1, -1);
    int answer = 0;
    for(bool b : is_early) answer += b ? 1 : 0;

    cout << answer;

    return 0;
}