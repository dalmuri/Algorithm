#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;
    
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    cin >> m;
    vector<tuple<int, int, int>> swap_costs(m);
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        swap_costs[i] = {a, b, cost};
    }

    using piv = pair<int, vector<int>>;
    priority_queue<piv, vector<piv>, greater<piv>> pq;
    map<vector<int>, int> dists;
    dists[arr] = 0;
    pq.push({0, arr});

    while(!pq.empty()){
        auto [now_dist, now] = pq.top();
        pq.pop();

        if(dists[now] < now_dist) continue;
        for(auto [a, b, cost] : swap_costs){
            vector<int> next(now);
            int next_dist = now_dist + cost;
            swap(next[a], next[b]);
            
            auto iter = dists.find(next);
            if(iter == dists.end() || next_dist < (*iter).second){
                dists[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    sort(arr.begin() + 1, arr.end());
    auto iter = dists.find(arr);
    cout << (iter != dists.end() ? (*iter).second : -1);

    return 0;
}