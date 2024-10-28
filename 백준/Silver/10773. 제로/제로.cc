#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int k;
    cin >> k;

    int num;
    stack<int> stk;
    for(int i = 0; i < k; i++){
        cin >> num;

        if(num == 0) stk.pop();
        else stk.push(num);
    }

    int sum = 0;
    while(!stk.empty()){
        sum += stk.top();
        stk.pop();
    }

    cout << sum;

    return 0;
}