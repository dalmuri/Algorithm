#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> sensors(n);
    for(int i = 0; i < n; i++) cin >> sensors[i];

    sort(sensors.begin(), sensors.end());

    priority_queue<int> pq;
    for(int i = 0; i + 1 < n; i++) pq.push(sensors[i + 1] - sensors[i]);

    int answer = sensors.back() - sensors.front();
    for(int i = 0; i < k - 1 && !pq.empty(); i++){
        answer -= pq.top();
        pq.pop();
    }

    cout << answer;

    return 0;
}