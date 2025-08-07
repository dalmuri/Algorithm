#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int r = 0, rr = 0, answer = 0;
    for(int i = 0, now; i < n; ++i){
        cin >> now;
        now = (now + r) % 2;

        answer += now;
        r = rr + now;
        rr = now;
    }

    cout << answer;

    return 0;
}