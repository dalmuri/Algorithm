#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 987654321;

    int n;
    cin >> n;

    vector<int> life(n);
    for(int i = 0; i < n; i++) cin >> life[i];

    vector<int> happy(n);
    for(int i = 0; i < n; i++) cin >> happy[i];

    vector<int> dp(101, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 100; j++){
            if(j - life[i] > 0) dp[j - life[i]] = max(dp[j - life[i]], dp[j] + happy[i]);
        }
    }

    cout << *max_element(dp.begin() + 1, dp.end());

    return 0;
}