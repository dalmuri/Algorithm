#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int roots[501];
bool visited[501];

int find_root(int num){
    if(roots[num] == 0) return num;
    return roots[num] = find_root(roots[num]);
}

void union_root(int a, int b){
    int root_a = find_root(a);
    int root_b = find_root(b);

    if(root_a == root_b) return;
    roots[max(root_a, root_b)] = min(root_a, root_b);
}

bool is_tree(int node, int parent, vector<vector<int>>& edges){
    visited[node] = true;

    bool result = true;
    for(int child : edges[node]){
        if(child == parent) continue;

        if(visited[child]) result = false;
        else result &= is_tree(child, node, edges);
    }

    return result;
}

int main(){
    FASTIO

    for(int t = 1; 1; t++){
        int n, m;
        cin >> n >> m;
        if(n == 0) break;

        memset(roots, 0, sizeof(int) * (n + 1));
        memset(visited, false, sizeof(bool) * (n + 1));
        vector<vector<int>> edges(n + 1);
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;

            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int answer = 0;
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;

            if(is_tree(i, -1, edges)) answer++;
        }

        cout << "Case " << t << ": ";
        if(answer == 0) cout << "No trees.\n";
        else if(answer == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << answer << " trees.\n";
    }

    return 0;
}