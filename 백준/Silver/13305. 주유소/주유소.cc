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
    int min_cost = costs[0];
    for(int i = 0; i < n - 1; i++){
        min_cost = min(min_cost, costs[i]);

        answer += min_cost * roads[i];
    }

    cout << answer;

    return 0;
}