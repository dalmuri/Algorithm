#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class node{
    string name;
    map<string, node> children;

public:
    node(){
        this->name = "";
    }

    node(string name){
        this->name = name;
    }

    void add(int idx, vector<string>& names){
        if(idx >= names.size()) return;

        auto iter = children.find(names[idx]);
        if(iter != children.end()){
            (*iter).second.add(idx + 1, names);
            return;
        }

        node new_node = node(names[idx]);
        new_node.add(idx + 1, names);
        children[names[idx]] = new_node;
    }

    void print(int floor){
        for(int i = 0; i < floor; i++) cout << "--";
        if(floor >= 0) cout << name << "\n";

        for(auto iter = children.begin(); iter != children.end(); iter++){
            (*iter).second.print(floor + 1);
        }
    }

    bool operator<(node& b){
        return this->name < b.name;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    node root = node();
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        vector<string> names(k);

        for(int j = 0; j < k; j++) cin >> names[j];

        root.add(0, names);
    }

    root.print(-1);

    return 0;
}