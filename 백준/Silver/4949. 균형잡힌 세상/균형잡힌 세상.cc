#include <string>
#include <iostream>
#include <stack>

using namespace std;

string check(string line){
    stack<char> stk;
    for(char c : line){
        if(c == '(' || c == '[') stk.push(c);
        else if(c == ')'){
            if(!stk.empty() && stk.top() == '(') stk.pop();
            else return "no";
        }
        else if(c == ']'){
            if(!stk.empty() && stk.top() == '[') stk.pop();
            else return "no";
        }
    }
    
    if(stk.empty()) return "yes";
    else return "no";
}

int main(){
    while(true){
        string line;
        getline(cin, line);
        
        if(line[0] == '.') break;
        
        cout << check(line) << endl;
    }
    
    return 0;
}