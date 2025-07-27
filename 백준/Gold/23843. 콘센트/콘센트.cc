#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> times(n);
    for(int i = 0; i < n; ++i) cin >> times[i];

    sort(times.rbegin(), times.rend());

    priority_queue<int, vector<int>, greater<int>> pq;
    int now = 0;
    for(int i = 0; i < n; ++i){
        if(pq.size() == m){
            now = max(now, pq.top());
            pq.pop();
        }
        
        pq.push(now + times[i]);
    }

    while(pq.size() > 1) pq.pop();

    cout << max(now, pq.top());

    return 0;
}