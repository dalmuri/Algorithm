#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m, j;
    cin >> n >> m >> j;

    int left = 1, right = m;
    int answer = 0;
    for(int i = 0; i < j; i++){
        int pos;
        cin >> pos;

        if(left <= pos && pos <= right) continue;
        else if(pos < left){
            answer += left - pos;
            left = pos;
            right = pos + m - 1;
        }
        else{
            answer += pos - right;
            right = pos;
            left = pos - m + 1;
        }
    }

    cout << answer;

    return 0;
}