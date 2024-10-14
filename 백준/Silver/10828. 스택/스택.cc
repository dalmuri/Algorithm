#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class Stack{
private:
    int point = -1;
    vector<int> stk = vector<int>(10000, 0);
public:
    bool empty(){
        return point == -1;
    }

    int size(){
        return point + 1;
    }

    void push(int e){
        stk[++point] = e;
    }

    int pop(){
        if(empty()) return -1;
        return stk[point--];
    }

    int top(){
        if(empty()) return -1;
        return stk[point];
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;
    Stack s;

    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "push"){
            int num;
            cin >> num;
            s.push(num);
        }
        else if(cmd == "pop"){
            cout << s.pop() << "\n";
        }
        else if(cmd == "size"){
            cout << s.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << (s.empty() ? 1 : 0) << "\n";
        }
        else{
            cout << s.top() << "\n";
        }
    }

    return 0;
}