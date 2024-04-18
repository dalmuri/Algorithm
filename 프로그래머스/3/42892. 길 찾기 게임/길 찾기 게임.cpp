#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int num;
    Node* left = NULL;
    Node* right = NULL;
};

Node* make_tree(int start, int end, vector<vector<int>>& nodes){
    if(start + 1 == end){
        Node* leaf = new Node();
        leaf->num = nodes[start][2];
        return leaf;
    }
    if(start + 1 > end) return NULL;
    
    int idx = max_element(nodes.begin() + start, nodes.begin() + end, [](vector<int> a, vector<int> b){ return a[1] < b[1]; }) - nodes.begin();
    
    Node* node = new Node();
    node->num = nodes[idx][2];
    node->left = make_tree(start, idx, nodes);
    node->right = make_tree(idx + 1, end, nodes);
    
    return node;
}

void preorder(Node* node, vector<int>& result){
    if(node == NULL) return;
    
    result.push_back(node->num);
    preorder(node->left, result);
    preorder(node->right, result);
}

void postorder(Node* node, vector<int>& result){
    if(node == NULL) return;
    
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int n = nodeinfo.size();
    for(int i = 0; i < nodeinfo.size(); i++) nodeinfo[i].push_back(i + 1);
    
    sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int> a, vector<int> b){ return a[0] < b[0]; });
    
    Node* root = make_tree(0, n, nodeinfo);
    
    vector<int> pre;
    preorder(root, pre);
    
    vector<int> post;
    postorder(root, post);
    
    return {pre, post};
}