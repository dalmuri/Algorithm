#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    cin >> str;

    int answer = 0;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 'K'){
            if(answer % 5 == 0) answer++;
        }
        else if(str[i] == 'O'){
            if(answer % 5 == 1) answer++;
        }
        else if(str[i] == 'R'){
            if(answer % 5 == 2) answer++;
        }
        else if(str[i] == 'E'){
            if(answer % 5 == 3) answer++;
        }
        else{
            if(answer % 5 == 4) answer++;
        }
    }

    cout << answer;

    return 0;
}