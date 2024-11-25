#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

map<string, string> root;
map<string, int> network;

string get_root(string& name){
    auto iter = root.find(name);
    if(iter->second == name) return name;

    return iter->second = get_root(iter->second);
}

int combine(string& a, string& b){
    string root_a = get_root(a);
    string root_b = get_root(b);

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
        root.clear();
        network.clear();

        int f;
        cin >> f;

        for(int i = 0; i < f; i++){
            string a, b;
            cin >> a >> b;

            root.insert({a, a});
            network.insert({a, 1});
            root.insert({b, b});
            network.insert({b, 1});

            cout << combine(a, b) << "\n";
        }
    }

    return 0;
}