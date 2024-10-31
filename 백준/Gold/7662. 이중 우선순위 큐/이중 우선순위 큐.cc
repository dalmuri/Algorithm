#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int k;
        cin >> k;

        priority_queue<int> max_q;
        priority_queue<int, vector<int>, greater<int>> min_q;
        map<int, int> cnt;
        int size = 0;
        for(int i = 0; i < k; i++){
            char cmd;
            int num;
            cin >> cmd >> num;

            if(cmd == 'I'){
                size++;
                cnt[num]++;
                max_q.push(num);
                min_q.push(num);
            }
            else{
                if(size == 0) continue;
                
                size--;
                if(num == 1){
                    while(cnt[max_q.top()] == 0) max_q.pop();

                    cnt[max_q.top()]--;
                    max_q.pop();
                }
                else{
                    while(cnt[min_q.top()] == 0) min_q.pop();
                    
                    cnt[min_q.top()]--;
                    min_q.pop();
                }
            }
        }

        if(size == 0) cout << "EMPTY\n";
        else{
            while(cnt[max_q.top()] == 0) max_q.pop();
            while(cnt[min_q.top()] == 0) min_q.pop();

            cout << max_q.top() << " " << min_q.top() << "\n";
        }
    }

    return 0;
}