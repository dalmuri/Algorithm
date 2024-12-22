#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> nge(n, -1);
    stack<int> stk;
    for(int i = n - 1; i >= 0; i--){
        while(!stk.empty() && stk.top() <= arr[i]) stk.pop();

        if(!stk.empty()) nge[i] = stk.top();
        stk.push(arr[i]);
    }

    for(int i = 0; i < n; i++) cout << nge[i] << " ";

    return 0;
}