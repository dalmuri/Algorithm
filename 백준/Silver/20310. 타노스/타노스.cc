#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string s;
    cin >> s;

    int cnt0 = accumulate(s.begin(), s.end(), 0, [](int acc, char e){ return acc + (e == '0' ? 1 : 0); });
    int cnt1 = s.size() - cnt0;

    cnt0 >>= 1;
    cnt1 >>= 1;

    for(int i = 0, cnt = 0; i < s.size(); ++i){
        if(s[i] == '1'){
            s[i] = ' ';
            if(++cnt >= cnt1) break;
        }
    }

    for(int i = s.size() - 1, cnt = 0; i >= 0; --i){
        if(s[i] == '0'){
            s[i] = ' ';
            if(++cnt >= cnt0) break;
        }
    }

    for(int i = 0; i < s.size(); ++i){
        if(s[i] != ' ') cout << s[i];
    }

    return 0;
}