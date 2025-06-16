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

        deque<char> dq;
        for(int i = 0; i < n; ++i){
            string card;
            cin >> card;
            if(card[0] <= dq.front()) dq.push_front(card[0]);
            else dq.push_back(card[0]);
        }

        while(!dq.empty()){
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }

    return 0;
}