#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    string s;
    cin >> s;

    int answer = -1, cnt = 0;
    stack<pair<char, int>> stk;
    for(int i = 0; i < n; ++i){
        if(!stk.empty() && stk.top().first != s[i]) stk.pop();
        else{
            stk.push({s[i], stk.empty() ? 1 : stk.top().second + 1});

            answer = max(answer, stk.top().second);
        }
    }
    if(!stk.empty()) answer = -1;
    
    cout << answer;

    return 0;
}