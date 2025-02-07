#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    int answer = 1;
    if(n == 2) answer = 1 + min(3, (m - 1) / 2);
    else if(n > 2){
        answer = max(min(4, m), m - 2);
    }

    cout << answer;

    return 0;
}