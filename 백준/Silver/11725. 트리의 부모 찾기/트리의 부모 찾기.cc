#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void search(int node, int parent, vector<int>& parents, vector<vector<int>>& tree){
    parents[node] = parent;

    for(int child : tree[node]){
        if(child == parent) continue;

        search(child, node, parents, tree);
    }
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> parents(n + 1);
    search(1, -1, parents, tree);

    for(int i = 2; i <= n; i++) cout << parents[i] << "\n";

    return 0;
}