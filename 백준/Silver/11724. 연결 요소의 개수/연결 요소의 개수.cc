#include <string>
#include <iostream>
#include <vector>
#include <set>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int find_root(int node, vector<int>& root){
    if(root[node] == node) return node;

    root[node] = find_root(root[node], root);
    return root[node];
}

void connect(int a, int b, vector<int>& root){
    int root_a = find_root(a, root);
    int root_b = find_root(b, root);

    root[max(root_a, root_b)] = min(root_a, root_b);
}


int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> root(n + 1);
    for(int i = 1; i < root.size(); i++) root[i] = i;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        connect(a, b, root);
    }

    set<int> answer;
    for(int i = 1; i <= n; i++){
        answer.insert(find_root(i, root));
    }

    cout << answer.size();

    return 0;
}