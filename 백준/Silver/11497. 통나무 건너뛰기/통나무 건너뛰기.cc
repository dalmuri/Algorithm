#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> logs(n);
        for(int i = 0; i < n; i++) cin >> logs[i];

        sort(logs.begin(), logs.end());

        deque<int> dq;
        for(int i = 0; i < n; i++){
            if(i & 1) dq.push_front(logs[i]);
            else dq.push_back(logs[i]);
        }

        int answer = abs(dq.front() - dq.back());
        int prev = dq.back();
        dq.pop_back();
        while(!dq.empty()){
            answer = max(answer, abs(prev - dq.back()));
            prev = dq.back();
            dq.pop_back();
        }

        cout << answer << "\n";
    }

    return 0;
}