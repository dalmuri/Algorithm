#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> roads(n - 1);
    vector<int> costs(n);
    for(int i = 0; i < n - 1; i++) cin >> roads[i];
    for(int i = 0; i < n; i++) cin >> costs[i];

    long long answer = 0ll;
    int dist = 0;
    int prev_min_cost = 1'000'000'001;
    for(int i = n - 2; i >= 0; i--){
        if(prev_min_cost >= costs[i]){
            prev_min_cost = costs[i];
            dist += roads[i];

            if(i == 0) answer += prev_min_cost * dist;
            continue;
        }
        
        answer += prev_min_cost * dist;
        prev_min_cost = costs[i];
        dist = roads[i];

        if(i == 0) answer += prev_min_cost * dist;
    }

    cout << answer;

    return 0;
}