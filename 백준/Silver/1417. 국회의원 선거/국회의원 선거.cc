#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int dasom;
    cin >> dasom;

    int answer = 0;
    if(n > 1){
        priority_queue<int> pq;
        for(int i = 1; i < n; i++){
            int num;
            cin >> num;

            pq.push(num);
        }

        while(dasom <= pq.top()){
            int top = pq.top();

            pq.pop();
            pq.push(top - 1);
            dasom++;
            answer++;
        }
    }

    cout << answer;

    return 0;
}