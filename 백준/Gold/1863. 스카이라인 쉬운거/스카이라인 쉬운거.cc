#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> skyline(n, vector<int>(2, 0)); // index, height
    for(int i = 0; i < n; i++){
        cin >> skyline[i][0];
        cin >> skyline[i][1];
    }
    
    stack<int> stk;
    stk.push(0);
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        int h = skyline[i][1];
        if(stk.top() < h){
            answer++;
            stk.push(h);
        }
        else{
            while(stk.top() > h) stk.pop();
            
            if(stk.top() < h){
                answer++;
                stk.push(h);
            }
        }
    }
    cout << answer << endl;
    
    return 0;
}