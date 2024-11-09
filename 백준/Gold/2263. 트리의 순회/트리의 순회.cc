#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> inorder;
vector<int> postorder;

struct node{
    int num;
    node* left = NULL;
    node* right = NULL;
};

node* make_tree(int in_start, int in_end, int post_start, int post_end){
    if(in_end < in_start) return NULL;
    node* now = new node;
    now->num = postorder[post_end];

    if(in_start == in_end) return now;

    int in_mid = find(inorder.begin() + in_start, inorder.begin() + in_end, postorder[post_end]) - inorder.begin();
    int left_len = in_mid - in_start;
    
    now->left = make_tree(in_start, in_mid - 1, post_start, post_start + left_len - 1);
    now->right = make_tree(in_mid + 1, in_end, post_start + left_len, post_end - 1);

    return now;
}

void print_preorder(node& e){
    cout << e.num << " ";
    if(e.left != NULL) print_preorder(*e.left);
    if(e.right != NULL) print_preorder(*e.right);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    inorder = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> inorder[i];

    postorder = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> postorder[i];

    node root = *make_tree(0, n - 1, 0, n - 1);
    print_preorder(root);

    return 0;
}