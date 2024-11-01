#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class node{
public:
    int num = 0;
    node* left = NULL;
    node* right = NULL;

    void push(int n){
        if(num == 0){
            num = n;
            return;
        }

        if(n < num){
            if(left == NULL){
                node* new_node = new node();
                left = new_node;
            }

            (*left).push(n);
        }
        else{
            if(right == NULL){
                node* new_node = new node();
                right = new_node;
            }

            (*right).push(n);
        }
    }

    void print(){
        if(num == 0) return;

        if(left != NULL) (*left).print();
        if(right != NULL) (*right).print();
        cout << num << "\n";
    }
};

int main(){
    FASTIO

    int num;
    node root;

    while(cin >> num){
        root.push(num);
    }

    root.print();

    return 0;
}