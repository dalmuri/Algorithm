#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void check(stack<char>& stk, string& boom){
    vector<char> comparison(boom.size());
    for(int i = boom.size() - 1; i >= 0; i--){
        comparison[i] = stk.top();
        stk.pop();
    }

    if(string(comparison.begin(), comparison.end()) == boom) return;
    for(int i = 0; i < boom.size(); i++) stk.push(comparison[i]);
}

int main(){
    FASTIO

    string str, boom;
    cin >> str >> boom;

    stack<char> stk;
    for(char c : str){
        stk.push(c);

        if(stk.top() == boom.back() && stk.size() >= boom.size()) check(stk, boom);
    }

    if(stk.size() == 0) cout << "FRULA";
    else{
        vector<char> answer(stk.size());
        for(int i = stk.size() - 1; i >= 0; i--){
            answer[i] = stk.top();
            stk.pop();
        }

        for(char c : answer) cout << c;
    }

    return 0;
}