#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const long long mod = 1'000'000'007ll;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < n; ++i){
            long long slime;
            cin >> slime;
            pq.push(slime);
        }

        long long answer = 1ll;
        while(pq.size() >= 2){
            long long energy = pq.top();
            pq.pop();
            energy *= pq.top();
            pq.pop();

            answer = (answer * (energy % mod)) % mod;
            pq.push(energy);
        }

        cout << answer << "\n";
    }

    return 0;
}