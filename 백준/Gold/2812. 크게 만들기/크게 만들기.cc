#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    string number;
    cin >> n >> k >> number;

    deque<char> dq;
    for(char num : number){
        while(k > 0 && !dq.empty() && dq.back() < num){
            dq.pop_back();
            k--;
        }

        dq.push_back(num);
    }

    while(k > 0 && !dq.empty()){
        dq.pop_back();
        k--;
    }

    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }

    return 0;
}