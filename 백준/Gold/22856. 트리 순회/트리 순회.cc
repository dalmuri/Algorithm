#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void traverse(int node, bool to_go_parent, vector<pair<int, int>>& tree, int& cnt){
    if(tree[node].first != -1){
        ++cnt;
        traverse(tree[node].first, true, tree, cnt);
    }

    if(tree[node].second != -1){
        ++cnt;
        traverse(tree[node].second, to_go_parent, tree, cnt);
    }

    if(to_go_parent) ++cnt;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> tree(n + 1);
    for(int i = 0; i < n; ++i){
        int node;
        cin >> node;

        cin >> tree[node].first >> tree[node].second;
    }

    int answer = 0;
    traverse(1, false, tree, answer);

    cout << answer;

    return 0;
}