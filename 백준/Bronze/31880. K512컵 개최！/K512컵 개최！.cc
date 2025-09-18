#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m, num;
    cin >> n >> m;

    long long answer = 0ll;
    while(n--){
        cin >> num;
        answer += num;
    }
    while(m--){
        cin >> num;
        if(num > 0) answer *= num;
    }

    cout << answer;

    return 0;
}