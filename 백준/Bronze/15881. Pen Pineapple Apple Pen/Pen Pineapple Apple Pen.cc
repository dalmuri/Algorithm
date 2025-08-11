#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    string str;
    cin >> str;

    int answer = 0;
    for(int i = 0, prev = 0; i < n; ++i){
        if(str[i] == 'p'){
            if(prev == 3) answer++, prev = 0;
            else prev = 1;
        }
        else if(str[i] == 'P'){
            if(prev == 1) prev++;
            else prev = 0;
        }
        else{
            if(prev == 2) prev++;
            else prev = 0;
        }
    }

    cout << answer;

    return 0;
}