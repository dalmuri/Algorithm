#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int quarter = 0, half = 0, quarter3 = 0;
    for(int i = 0; i < n; ++i){
        string ratio;
        cin >> ratio;
        
        if(ratio[0] == '1' && ratio[2] == '4') quarter++;
        else if(ratio[0] == '3') quarter3++;
        else half++;
    }

    int answer = 0;
    if(quarter > 0 && quarter3 > 0){
        int tmp = min(quarter, quarter3);
        answer += tmp;
        quarter -= tmp;
        quarter3 -= tmp;
    }
    if(half >= 2){
        answer += half / 2;
        half &= 1;
    }
    if(quarter > 0 && half == 1){
        answer++;
        half = 0;
        quarter -= min(quarter, 2);
    }
    if(quarter > 0){
        answer += quarter / 4 + min(1, quarter % 4);
    }
    if(half > 0){
        answer += half;
    }
    if(quarter3 > 0){
        answer += quarter3;
    }

    cout << answer;

    return 0;
}