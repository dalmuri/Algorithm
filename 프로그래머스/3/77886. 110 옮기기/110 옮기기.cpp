#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(string x : s){
        // extract 110
        stack<char> stk;
        int num1 = 0; // 연속해서 1이 나온 개수
        int cnt = 0; // 110 개수
        for(char c : x){
            if(c == '1'){
                stk.push(c);
                num1++;
            }
            else{
                if(num1 >= 2){
                    stk.pop();
                    stk.pop();
                    num1 -= 2;
                    cnt++;
                }
                else{
                    stk.push(c);
                    num1 = 0;
                }
            }
        }
        string new_x = "";
        while(!stk.empty()){
            new_x += stk.top();
            stk.pop();
        }
        reverse(new_x.begin(), new_x.end());
        
        // insert 110
        string to_insert = "";
        for(int i = 0; i < cnt; i++) to_insert += "110";
        
        int idx_111 = new_x.find("111");
        if(idx_111 != string::npos){
            new_x.insert(idx_111, to_insert);
        }
        else{
            int idx_last0 = new_x.rfind('0');
            if(idx_last0 != string::npos) new_x.insert(idx_last0 + 1, to_insert);
            else new_x = to_insert + new_x;
        }
        
        // answer
        answer.push_back(new_x);
    }
    return answer;
}