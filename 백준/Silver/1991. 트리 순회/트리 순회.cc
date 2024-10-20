#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void preorder(char node, vector<vector<char>>& tree){
    if(node == '.') return;

    cout << node;
    preorder(tree[node - 'A'][0], tree);
    preorder(tree[node - 'A'][1], tree);
}

void inorder(char node, vector<vector<char>>& tree){
    if(node == '.') return;

    inorder(tree[node - 'A'][0], tree);
    cout << node;
    inorder(tree[node - 'A'][1], tree);
}

void postorder(char node, vector<vector<char>>& tree){
    if(node == '.') return;

    postorder(tree[node - 'A'][0], tree);
    postorder(tree[node - 'A'][1], tree);
    cout << node;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<char>> tree(n, vector<char>());
    for(int i = 0; i < n; i++){
        char node, left, right;
        cin >> node >> left >> right;
        tree[node - 'A'] = {left, right};
    }

    preorder('A', tree);
    cout << "\n";
    inorder('A', tree);
    cout << "\n";
    postorder('A', tree);

    return 0;
}