#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

unordered_map<string, int> indexs;
map<int, int> root;
map<int, int> network;

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
    auto iter = root.find(idx);
    if(iter->second == idx) return idx;

    return iter->second = get_root(iter->second);
}

int combine(int a, int b){
    int root_a = get_root(a);
    int root_b = get_root(b);

    if(root_a == root_b) return network[root_a];

    if(root_a > root_b) swap(root_a, root_b);

    auto iter_a = network.find(root_a);
    auto iter_b = network.find(root_b);
    
    iter_a->second += iter_b->second;
    iter_b->second = 0;

    root[root_b] = root_a;

    return iter_a->second;
}

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        indexs.clear();
        root.clear();
        network.clear();

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