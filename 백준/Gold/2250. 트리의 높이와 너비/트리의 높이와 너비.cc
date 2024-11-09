#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct node{
    int num;
    int level;
    node* left = NULL;
    node* right = NULL;
};

node* make_tree(int num, int level, vector<pair<int, int>>& children){
    node* now = new node;
    now->num = num;
    now->level = level;

    if(children[num].first != -1) now->left = make_tree(children[num].first, level + 1, children);
    if(children[num].second != -1) now->right = make_tree(children[num].second, level + 1, children);

    return now;
}

void set_col(node& now, int& col, vector<pair<int, int>>& columns){
    if(now.left != NULL) set_col(*now.left, col, columns);

    col++;
    columns[now.level].first = min(columns[now.level].first, col);
    columns[now.level].second = max(columns[now.level].second, col);

    if(now.right != NULL) set_col(*now.right, col, columns);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> children(n + 1);
    vector<bool> has_parent(n + 1, false);

    for(int i = 0; i < n; i++){
        int num, left, right;
        cin >> num >> left >> right;
        children[num] = {left, right};

        if(left != -1) has_parent[left] = true;
        if(right != -1) has_parent[right] = true;
    }

    int root_num;
    for(int i = 1; i <= n; i++){
        if(!has_parent[i]){
            root_num = i;
            break;
        }
    }

    node root = *make_tree(root_num, 1, children);

    vector<pair<int, int>> columns(n + 1, pair<int, int>(n + 1, 0)); // columns[i] = {min col of level i, max col of level i}
    int col = 0;
    set_col(root, col, columns);
    
    pair<int, int> answer = {0, 0};
    for(int i = 1; i <= n; i++){
        int area = columns[i].second - columns[i].first + 1;
        if(answer.second < area){
            answer.first = i;
            answer.second = area;
        }
    }

    cout << answer.first << " " << answer.second;

    return 0;
}