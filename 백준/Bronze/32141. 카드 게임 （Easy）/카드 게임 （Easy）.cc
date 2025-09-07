#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, h, card, answer = 0;
    cin >> n >> h;

    while(n--){
        cin >> card;
        h -= card;
        answer++;

        if(h <= 0) break;
    }

    if(h > 0) answer = -1;

    cout << answer;

    return 0;
}