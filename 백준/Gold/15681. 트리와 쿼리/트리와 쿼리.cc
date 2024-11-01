#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void make_tree(int node, int parent, vector<int>& count, vector<vector<int>>& tree){
    for(int child : tree[node]){
        if(child == parent) continue;

        make_tree(child, node, count, tree);
        count[node] += count[child];
    }
}

int main(){
    FASTIO

    int n, r, q;
    cin >> n >> r >> q;
    vector<vector<int>> tree(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> count(n + 1, 1);
    make_tree(r, -1, count, tree);
    for(int i = 0; i < q; i++){
        int query;
        cin >> query;

        cout << count[query] << "\n";
    }

    return 0;
}