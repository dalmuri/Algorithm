#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        long long answer = 0ll;
        stack<pair<int, int>> stk;
        for(int i = 0; i <= n; i++){
            int h;
            
            if(i < n) cin >> h;
            else h = 0;

            while(!stk.empty() && stk.top().second > h){
                auto [idx, height] = stk.top();
                stk.pop();

                long long width;
                if(stk.empty()) width = i;
                else width = i - stk.top().first - 1;

                answer = max(answer, width * height);
            }

            stk.push({i, h});
        }

        cout << answer << "\n";
    }

    return 0;
}