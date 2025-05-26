#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;
    
    vector<int> speeds(n);
    for(int i = 0; i < n; ++i) cin >> speeds[i];

    long long answer = 0ll;
    int prev = 0;
    for(int i = n - 1; i >= 0; --i) answer += prev = min(speeds[i], prev + 1);
    
    cout << answer;

    return 0;
}