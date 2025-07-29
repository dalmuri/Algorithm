#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> weights(n);
    for(int i = 0; i < n; ++i) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int answer = 0, l = 0, r = weights.size() - 1;
    while(l < r){
        if(weights[l] + weights[r] > k){
            r--;
        }
        else{
            answer++;
            l++;
            r--;
        }
    }

    cout << answer;

    return 0;
}