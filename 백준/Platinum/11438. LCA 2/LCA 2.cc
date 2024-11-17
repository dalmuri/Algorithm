#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> edges[100'001];
int parents[100'001][18]; // parents[i][j] = i노드의 2^j개 위의 조상
int depth[100'001];
int max_depth;

void make_tree(int num, int parent, int d){
    parents[num][0] = parent;
    depth[num] = d;

    for(int child : edges[num]){
        if(child == parent) continue;

        make_tree(child, num, d + 1);
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for(int i = 0; diff > 0; i++, diff >>= 1){
        if(diff & 1) a = parents[a][i];
    }

    if(a == b) return a;

    for(int d = max_depth; d >= 0; d--){
        if(parents[a][d] != 0 && parents[a][d] != parents[b][d]){
            a = parents[a][d];
            b = parents[b][d];
        }
    }
    return parents[a][0];
}

int main(){
    FASTIO

    int n, m;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    make_tree(1, 0, 1);

    max_depth = log2(n);
    for(int d = 1; d <= max_depth; d++){
        for(int i = 2; i <= n; i++){
            if(parents[i][d - 1] != 0) parents[i][d] = parents[parents[i][d - 1]][d - 1];
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}