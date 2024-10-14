#include <string>
#include <iostream>
#include <unordered_set>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int m;
    cin >> m;

    unordered_set<int> s;
    for(int i = 0; i < m; i++){
        string cmd;
        int num;
        cin >> cmd;

        if(cmd == "add"){
            cin >> num;
            s.insert(num);
        }
        else if(cmd == "remove"){
            cin >> num;
            s.erase(num);
        }
        else if(cmd == "check"){
            cin >> num;
            cout << s.count(num) << "\n";
        }
        else if(cmd == "toggle"){
            cin >> num;
            if(s.count(num)) s.erase(num);
            else s.insert(num);
        }
        else if(cmd == "all"){
            s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        }
        else{
            s.clear();
        }
    }

    return 0;
}