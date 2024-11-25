#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

unordered_map<string, int> indexs;
int root[200'001];
int network[200'001];

int get_index(string& name){
    auto iter = indexs.find(name);
    if(iter != indexs.end()) return iter->second;

    int idx = indexs.size();
    indexs[name] = idx;
    root[idx] = idx;
    network[idx] = 1;

    return idx;
}

int get_root(int idx){
    if(root[idx] == idx) return idx;
    return root[idx] = get_root(root[idx]);
}

int combine(int a, int b){
    int root_a = get_root(a);
    int root_b = get_root(b);

    if(root_a == root_b) return network[root_a];

    if(root_a > root_b) swap(root_a, root_b);
    
    network[root_a] += network[root_b];
    network[root_b] = 0;

    root[root_b] = root_a;

    return network[root_a];
}

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        indexs.clear();

        int f;
        cin >> f;

        for(int i = 0; i < f; i++){
            string a, b;
            cin >> a >> b;

            int idx_a = get_index(a);
            int idx_b = get_index(b);

            cout << combine(idx_a, idx_b) << "\n";
        }
    }

    return 0;
}