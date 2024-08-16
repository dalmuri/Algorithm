#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for(string op : operations){
        int num = stoi(op.substr(2));
        if(op[0] == 'I'){
            ms.insert(num);
        }
        else if(num == 1){
            if(ms.size() > 0) ms.erase(--ms.end());
        }
        else{
            if(ms.size() > 0) ms.erase(ms.begin());
        }
    }
    if(ms.size() == 0) return {0, 0};
    return {*--ms.end(), *ms.begin()};
}