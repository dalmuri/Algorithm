#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int root[100'001];

int find_root(int node){
    if(root[node] == 0) return node;
    return root[node] = find_root(root[node]);
}

int union_root(int a, int b){
    int root_a = find_root(a);
    int root_b = find_root(b);

    if(root_a == root_b) return 1;

    if(root_a < root_b) swap(root_a, root_b);
    root[root_a] = root_b;

    return 0;
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    int answer = -1;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        answer += union_root(u, v);
    }

    for(int i = 1; i <= n; ++i){
        if(find_root(i) == i) ++answer;
    }

    cout << answer;

    return 0;
}