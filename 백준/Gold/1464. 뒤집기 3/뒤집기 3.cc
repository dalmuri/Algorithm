#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string s;
    cin >> s;

    deque<char> dq;
    dq.push_back(s[0]);
    for(int i = 1; i < s.size(); ++i){
        if(dq.back() < s[i]) dq.push_front(s[i]);
        else dq.push_back(s[i]);
    }

    for(auto iter = dq.rbegin(); iter != dq.rend(); ++iter) cout << *iter;

    return 0;
}