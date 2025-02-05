#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int minimum(string num){
    for(int i = 0; i < num.size(); i++){
        if(num[i] == '6') num[i] = '5';
    }

    return stoi(num);
}

int maximum(string num){
    for(int i = 0; i < num.size(); i++){
        if(num[i] == '5') num[i] = '6';
    }

    return stoi(num);
}

int main(){
    FASTIO

    string a, b;
    cin >> a >> b;

    cout << minimum(a) + minimum(b) << " " << maximum(a) + maximum(b);

    return 0;
}