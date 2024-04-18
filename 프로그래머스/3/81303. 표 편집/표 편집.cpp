#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class node{
public:
    int num;
    node* left = NULL;
    node* right = NULL;
    bool deleted = false;
    
    node(int _num){
        num = _num;
    }
    
    void remove(){
        if(left != NULL) left->right = right;
        if(right != NULL) right->left = left;
        deleted = true;
    }
    
    void restore(){
        if(left != NULL) left->right = this;
        if(right != NULL) right->left = this;
        deleted = false;
    }
};

node* move_row(int dist, node* now){
    if(dist > 0){
        return move_row(dist - 1, now->right);
    }
    else if(dist < 0){
        return move_row(dist + 1, now->left);
    }
    else return now;
}

string solution(int n, int k, vector<string> cmd) {
    vector<node*> nodes(n);
    stack<int> deleted;
    for(int i = 0; i < n; i++){
        nodes[i] = new node(i);
        if(i > 0){
            nodes[i]->left = nodes[i - 1];
            nodes[i - 1]->right = nodes[i];
        }
    }
    
    node* now = nodes[k];
    
    for(string c : cmd){
        if(c[0] == 'U') now = move_row(-stoi(c.substr(2)), now);
        else if(c[0] == 'D') now = move_row(stoi(c.substr(2)), now);
        else if(c[0] == 'C'){
            deleted.push(now->num);
            now->remove();
            if(now->right == NULL) now = move_row(-1, now);
            else now = move_row(1, now);
        }
        else{
            nodes[deleted.top()]->restore();
            deleted.pop();
        }
    }
    
    string answer = "";
    for(int i = 0; i < n; i++){
        if(nodes[i]->deleted) answer += "X";
        else answer += "O";
    }
    return answer;
}