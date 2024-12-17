#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int costs[1'000'000];

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) cin >> costs[i];

        int max_cost = costs[n - 1];
        long long answer = 0ll;
        for(int i = n - 2; i >= 0; i--){
            if(costs[i] > max_cost) max_cost = costs[i];
            else answer += max_cost - costs[i];
        }

        cout << answer << "\n";
    }

    return 0;
}