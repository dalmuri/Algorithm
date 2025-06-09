#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0, cnt = 0;
    for(int i = 0, high = 0; i < n; ++i){
        int height;
        cin >> height;

        if(high > height) cnt++;
        else{
            answer = max(answer, cnt);
            cnt = 0;
            high = height;
        }
    }
    answer = max(answer, cnt);

    cout << answer;

    return 0;
}