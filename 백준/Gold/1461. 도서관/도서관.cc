#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    priority_queue<int> pos_pq;
    priority_queue<int, vector<int>, greater<int>> neg_pq;

    for(int i = 0; i < n; i++){
        int p;
        cin >> p;

        if(p > 0) pos_pq.push(p);
        else neg_pq.push(p);
    }

    int max_pos_dist = pos_pq.empty() ? 0 : pos_pq.top();
    int max_neg_dist = neg_pq.empty() ? 0 : -neg_pq.top();
    int dist = -max(max_pos_dist, max_neg_dist);
    while(!pos_pq.empty()){
        dist += pos_pq.top() * 2;
        for(int i = 0; i < m && !pos_pq.empty(); i++) pos_pq.pop();
    }

    while(!neg_pq.empty()){
        dist += -neg_pq.top() * 2;
        for(int i = 0; i < m && !neg_pq.empty(); i++) neg_pq.pop();
    }

    cout << dist;

    return 0;
}