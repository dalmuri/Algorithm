#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct node{
    char c = '_';
    vector<node*> children;

    node(char c){
        this->c = c;
    }
};

void make(int idx, node& now, string& str){
    if(idx == str.size()) return;
    
    if(now.children.empty()) now.children = vector<node*>(26);
    if(now.children[str[idx] - 'a'] == nullptr) now.children[str[idx] - 'a'] = new node(str[idx]);
    make(idx + 1, *now.children[str[idx] - 'a'], str);
}

bool check(int idx, node& now, string& str){
    if(idx == str.size()) return true;
    if(idx > str.size()) return false;

    if(now.children.empty()) return false;
    if(now.children[str[idx] - 'a'] == nullptr) return false;
    return check(idx + 1, *now.children[str[idx] - 'a'], str);
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    node root = node('_');
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;

        make(0, root, str);
    }

    int answer = 0;
    for(int i = 0; i < m; ++i){
        string str;
        cin >> str;

        answer += check(0, root, str);
    }

    cout << answer;

    return 0;
}