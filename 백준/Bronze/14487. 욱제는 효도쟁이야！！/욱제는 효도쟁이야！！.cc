#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0, max_cost = 0;
    for(int i = 0, cost; i < n; ++i){
        cin >> cost;
        max_cost = max(max_cost, cost);
        answer += cost;
    }

    answer -= max_cost;
    cout << answer;

    return 0;
}