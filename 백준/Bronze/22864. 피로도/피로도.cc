#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int fatigue = 0;
    int answer = 0;
    for(int i = 0; i < 24; ++i){
        if(fatigue + a <= m){
            fatigue += a;
            answer += b;
        }
        else{
            fatigue = max(0, fatigue - c);
        }
    }

    cout << answer;

    return 0;
}