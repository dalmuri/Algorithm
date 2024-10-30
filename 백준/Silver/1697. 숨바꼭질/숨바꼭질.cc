#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int inf = 100'001, n, k;
vector<int> times;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void move(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({n, 0});

    while(!pq.empty()){
        int pos = pq.top().first;
        int sec = pq.top().second;
        pq.pop();

        if(pos == k) return;
        if(times[pos] < sec) continue;

        if(pos - 1 >= 0 && times[pos - 1] > sec + 1){
            times[pos - 1] = sec + 1;
            pq.push({pos - 1, sec + 1});
        }

        if(pos + 1 < times.size() && times[pos + 1] > sec + 1){
            times[pos + 1] = sec + 1;
            pq.push({pos + 1, sec + 1});
        }

        if(pos * 2 < times.size() && times[pos * 2] > sec + 1){
            times[pos * 2] = sec + 1;
            pq.push({pos * 2, sec + 1});
        }
    }
}

int main(){
    FASTIO
    
    cin >> n >> k;

    times = vector<int>(max(n, k) * 2 + 1, inf);
    times[n] = 0;

    move();

    cout << times[k];

    return 0;
}