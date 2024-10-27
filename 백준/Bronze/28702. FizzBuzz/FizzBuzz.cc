#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int num;
    for(int i = 3; i >= 1; i--){
        string str;
        cin >> str;
        
        if('0' <= str[0] && str[0] <= '9') num = stoi(str) + i;
    }

    if(num % 3 == 0 && num % 5 == 0) cout << "FizzBuzz";
    else if(num % 3 == 0) cout << "Fizz";
    else if(num % 5 == 0) cout << "Buzz";
    else cout << num;

    return 0;
}