#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    int answer = 0;
    for(int i = 0, prev = -1, now; i < n; ++i, prev = now){
        cin >> now;

        if(prev < now) continue;
        
        now += k;
        answer++;
        if(prev < now) continue;

        answer = -1;
        break;
    }

    cout << answer;

    return 0;
}