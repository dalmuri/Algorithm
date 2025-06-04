#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0;
    for(int i = 0, prev = 0, height; i < n; ++i, prev = height){
        cin >> height;

        if(prev > height) continue;
        answer++;
    }

    cout << answer;

    return 0;
}