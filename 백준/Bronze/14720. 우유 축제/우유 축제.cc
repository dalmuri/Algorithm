#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0;
    for(int i = 0, next = 0, milk; i < n; ++i){
        cin >> milk;
        if(milk == next){
            answer++;
            next = (next + 1) % 3;
        }
    }

    cout << answer;

    return 0;
}