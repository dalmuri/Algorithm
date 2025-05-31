#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    priority_queue<int> pq;
    for(int i = 0; i < n; ++i){
        int snow;
        cin >> snow;

        pq.push(snow);
    }

    int answer = 0;
    while(pq.size() >= 2){
        int snow1 = pq.top();
        pq.pop();

        int snow2 = pq.top();
        pq.pop();

        answer += snow2;
        if(answer > 1440) break;
        if(snow1 > snow2) pq.push(snow1 - snow2);
    }
    if(pq.size() > 0) answer += pq.top();
    
    cout << (answer <= 1440 ? answer : -1);

    return 0;
}