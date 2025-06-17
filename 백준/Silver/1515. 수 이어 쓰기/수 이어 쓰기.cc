#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string number;
    cin >> number;

    for(int i = 1, idx = 0; true; ++i){
        string now = to_string(i);
        for(char c : now){
            if(number[idx] == c && ++idx == number.size()){
                cout << now;
                return 0;
            }
        }
    }

    return 0;
}