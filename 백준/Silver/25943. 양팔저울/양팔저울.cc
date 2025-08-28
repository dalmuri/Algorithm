#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int weights[7] = {100, 50, 20, 10, 5, 2, 1};

    int n;
    cin >> n;

    int diff = 0;
    for(int i = 0, w; i < n; ++i){
        cin >> w;

        if(diff <= 0) diff += w;
        else diff -= w;
    }

    diff = abs(diff);

    int answer = 0;
    for(int i = 0; i < 7; ++i){
        answer += diff / weights[i];
        diff %= weights[i];
    }

    cout << answer;

    return 0;
}