#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int mod = 1'000'000;

    string code;
    cin >> code;

    vector<int> decode(code.size(), 0); // decode[i] = [0, i]를 해석할 수 있는 경우의 수
    if(code[0] != '0') decode[0] = 1;

    for(int i = 1; i < code.size(); i++){
        if(code[i] != '0') decode[i] = decode[i - 1];
        if(code[i - 1] == '1' || (code[i - 1] == '2' && code[i] <= '6')){
            if(i == 1) decode[i] += 1;
            else decode[i] += decode[i - 2];
        }

        decode[i] %= mod;
    }

    cout << decode.back();
    return 0;
}