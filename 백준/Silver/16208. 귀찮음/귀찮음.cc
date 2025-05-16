#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> sticks(n);
    for(int i = 0; i < n; ++i) cin >> sticks[i];

    long long sum = accumulate(sticks.begin(), sticks.end(), 0ll);
    long long answer = 0ll;
    for(int i = 0; i < n; ++i){
        sum -= sticks[i];
        answer += sum * sticks[i];
    }

    cout << answer;

    return 0;
}