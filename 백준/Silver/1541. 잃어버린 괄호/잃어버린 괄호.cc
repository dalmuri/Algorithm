#include <iostream>
#include <string>

using namespace std;

int main(){
    string expression;
    getline(cin, expression);
    expression += '+';
    
    int answer = 0;
    
    int prev_oper = -1;
    bool is_minus = false;
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '+' || expression[i] == '-'){
            int num = stoi(expression.substr(prev_oper + 1, i - prev_oper - 1));
            if(is_minus) num *= -1;
            answer += num;
            
            if(expression[i] == '-') is_minus = true;
            prev_oper = i;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}