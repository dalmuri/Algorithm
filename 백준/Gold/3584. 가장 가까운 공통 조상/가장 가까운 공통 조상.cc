#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int parents[10'001];
int level[10'001];

void update_level(int node, int lvl, vector<vector<int>>& children){
    level[node] = lvl;
    for(int child : children[node]){
        update_level(child, lvl + 1, children);
    }
}

int lca(int a, int b){
    if(a == b) return a;
    if(level[a] == level[b]) return lca(parents[a], parents[b]);
    if(level[a] < level[b]) return lca(a, parents[b]);
    return lca(parents[a], b);
}

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n;
        vector<bool> has_parent(n + 1, false);
        vector<vector<int>> children(n + 1);
        for(int i = 0; i < n - 1; i++){
            cin >> a >> b;
            has_parent[b] = true;
            parents[b] = a;
            children[a].push_back(b);
        }

        int root = find(has_parent.begin() + 1, has_parent.end(), false) - has_parent.begin();
        update_level(root, 1, children);

        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}