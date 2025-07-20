#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    using pii = pair<int, int>;

    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> beers(k); // (선호도, 도수)
    for(int i = 0; i < k; ++i) cin >> beers[i].first >> beers[i].second;

    sort(beers.begin(), beers.end(), [](pii a, pii b){
        if(a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0ll;
    int answer = -1;
    for(int i = 0; i < k; ++i){
        if(pq.size() >= n){
            sum -= pq.top();
            pq.pop();
        }

        pq.push(beers[i].first);
        sum += beers[i].first;

        if(pq.size() >= n && sum >= m){
            answer = beers[i].second;
            break;
        }
    }

    cout << answer;

    return 0;
}