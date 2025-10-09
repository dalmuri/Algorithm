#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;

    vector<pair<int, int>> points(n); // (만족도, 거리)
    for(int i = 0; i < n; ++i) cin >> points[i].second >> points[i].first;

    sort(points.rbegin(), points.rend());

    long long answer = 0ll;
    for(int i = 0, prev = 0; i < n; ++i){
        if(points[i].second < prev) continue;

        answer += (long long)(points[i].second - prev) * (rf - rb) * points[i].first;
        prev = points[i].second;
    }

    cout << answer;

    return 0;
}