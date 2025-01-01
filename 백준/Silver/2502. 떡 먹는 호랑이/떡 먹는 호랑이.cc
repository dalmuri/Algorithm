#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

using pii = pair<int, int>;
pii operator+(const pii& a, const pii& b){
    return {a.first + b.first, a.second + b.second};
}

int main(){
    FASTIO

    int d, k;
    cin >> d >> k;

    vector<pii> dp(d + 1);
    dp[1] = {1, 0};
    dp[2] = {0, 1};
    for(int i = 3; i <= d; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int a = 1, b;
    for(; a <= 100'000; a++){
        if((k - a * dp[d].first) % dp[d].second == 0){
            b = (k - a * dp[d].first) / dp[d].second;
            break;
        }
    }

    cout << a << "\n" << b;

    return 0;
}