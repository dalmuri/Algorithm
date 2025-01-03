#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    cin >> str;

    int cnt = 0;
    string answer = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '.'){
            if(cnt & 1){
                answer = "-1";
                break;
            }
            while(cnt >= 4){
                answer += "AAAA";
                cnt -= 4;
            }
            if(cnt >= 2){
                answer += "BB";
                cnt -= 2;
            }
            answer.push_back('.');
        }
        else{
            cnt++;
        }
    }

    if(cnt & 1){
        answer = "-1";
    }
    else{
        while(cnt >= 4){
            answer += "AAAA";
            cnt -= 4;
        }
        if(cnt >= 2){
            answer += "BB";
        }
    }
    
    cout << answer;

    return 0;
}