#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, a, d;
    cin >> n >> a >> d;

    int now = a, answer = 0;
    for(int i = 0, sound; i < n; ++i){
        cin >> sound;
        
        if(now == sound){
            answer++;
            now += d;
        }
    }

    cout << answer;

    return 0;
}