#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class Queue{
private:
    int fron = 0;
    int rear = 0;
    vector<int> q = vector<int>(10000);
public:
    bool empty(){
        return fron == rear;
    }

    int size(){
        return rear - fron;
    }

    int front(){
        if(empty()) return -1;
        return q[fron];
    }

    int back(){
        if(empty()) return -1;
        return q[rear - 1];
    }

    void push(int e){
        q[rear++] = e;
    }

    int pop(){
        if(empty()) return -1;
        return q[fron++];
    }
};

int main(){
    FASTIO

    Queue q;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "push"){
            int num;
            cin >> num;
            q.push(num);
        }
        else if(cmd == "pop"){
            cout << q.pop() << "\n";
        }
        else if(cmd == "size"){
            cout << q.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << q.empty() << "\n";
        }
        else if(cmd == "front"){
            cout << q.front() << "\n";
        }
        else{
            cout << q.back() << "\n";
        }
    }

    return 0;
}