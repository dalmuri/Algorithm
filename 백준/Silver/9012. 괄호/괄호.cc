#include <iostream>
#include <string>
#include <stack>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool valid(string ps){
    stack<char> stk;
    for(char c : ps){
        if(c == '(') stk.push(c);
        else{
            if(stk.empty()) return false;
            else stk.pop();
        }
    }
    
    return stk.empty();
}

int main()
{
    FASTIO;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string ps;
        cin >> ps;
        
        cout << (valid(ps) ? "YES\n" : "NO\n");
    }

    return 0;
}
