#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, x, y, answer = 0;
    cin >> n >> x >> y;

    if(n > 1){
        if((x == 1 || x == n) && (y == 1 || y == n)) answer = 2;
        else if(x == 1 || x == n || y == 1 || y == n) answer = 3;
        else answer = 4;
    }

    cout << answer;

    return 0;
}