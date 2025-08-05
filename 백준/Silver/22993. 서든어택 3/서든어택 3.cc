#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    long long now;
    cin >> now;
    for(int i = 1, atk; i < n; ++i){
        cin >> atk;

        if(atk < now) now += atk;
        else pq.push(atk);
    }

    while(!pq.empty() && pq.top() < now){
        now += pq.top();
        pq.pop();
    }

    cout << (pq.empty() ? "Yes" : "No");

    return 0;
}