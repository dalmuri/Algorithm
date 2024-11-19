#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> edges[500'001];
int odd = 0;

void make_tree(int node, int parent, int level){
    if(edges[node].size() == 1){
        odd = (odd + level) & 1;
    }

    for(int child : edges[node]){
        if(child == parent) continue;

        make_tree(child, node, level + 1);
    }
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    make_tree(1, -1, 0);
    cout << (odd ? "Yes" : "No");

    return 0;
}