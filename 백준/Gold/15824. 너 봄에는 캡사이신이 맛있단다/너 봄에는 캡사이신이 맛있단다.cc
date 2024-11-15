#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int mod = 1'000'000'007;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> foods(n);
    for(int i = 0; i < n; i++) cin >> foods[i];

    sort(foods.begin(), foods.end());

    vector<long long> exp(n, 0ll); // exp[i] = 2^i % mod;
    exp[0] = 1ll;
    for(int i = 1; i < n; i++){
        exp[i] = (exp[i - 1] << 1) % mod;
    }

    long long answer = 0ll;
    for(int i = 0; i < n; i++){
        answer += (long long)foods[i] * (exp[i] - exp[n - 1 - i]);
        answer %= mod;
    }

    cout << answer;

    return 0;
}