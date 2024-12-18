#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < n; i++){
        int card;
        cin >> card;

        pq.push(card);
    }

    while(m--){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        pq.push(a + b);
        pq.push(a + b);
    }

    long long answer = 0ll;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }

    cout << answer;

    return 0;
}