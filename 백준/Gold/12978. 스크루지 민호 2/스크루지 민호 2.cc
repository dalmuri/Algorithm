#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> edges[100'001];

bool is_leaf(int node, int parent, int& answer){
    bool has_leaf_child = false;
    for(int child : edges[node]){
        if(child == parent) continue;

        has_leaf_child |= is_leaf(child, node, answer);
    }

    if(has_leaf_child) answer++;

    return !has_leaf_child;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int answer = 0;
    is_leaf(1, -1, answer);

    cout << answer;

    return 0;
}