#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string calc(string& str){
    string res = "";
    stack<char> stk;
    for(int i = 0; i < str.size(); i++){
        if('A' <= str[i] && str[i] <= 'Z') res += str[i];
        else if(str[i] == '+' || str[i] == '-'){
            while(!stk.empty() && stk.top() != '('){
                res += stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
        else if(str[i] == '*' || str[i] == '/'){
            while(!stk.empty() && stk.top() != '+' && stk.top() != '-' && stk.top() != '('){
                res += stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
        else if(str[i] == '('){
            stk.push(str[i]);
        }
        else{
            while(!stk.empty() && stk.top() != '('){
                res += stk.top();
                stk.pop();
            }
            stk.pop();
        }
    }

    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main(){
    FASTIO

    string str;
    cin >> str;

    cout << calc(str);

    return 0;
}