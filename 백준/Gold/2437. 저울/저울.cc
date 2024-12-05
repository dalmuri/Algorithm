#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int answer = 1;
    for(int weight : weights){
        if(answer < weight) break;

        answer += weight;
    }

    cout << answer;

    return 0;
}