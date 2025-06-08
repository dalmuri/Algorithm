#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string number;
    cin >> number;

    // big
    string big = "";
    bool has_k = false;
    int cnt_m = 0;
    for(int i = number.size() - 1; i >= 0; --i){
        if(number[i] == 'K'){
            big += string(cnt_m, '0');
            if(has_k) big.push_back('5');

            has_k = true;
            cnt_m = 0;
        }
        else if(has_k){
            cnt_m++;
        }
        else{
            big.push_back('1');
        }
    }
    if(has_k){
        big += string(cnt_m, '0');
        big.push_back('5');
    }
    reverse(big.begin(), big.end());

    // small
    string small = "";
    cnt_m = 0;
    for(int i = 0; i < number.size(); ++i){
        if(number[i] == 'M'){
            cnt_m++;
        }
        else{
            if(cnt_m > 0){
                small.push_back('1');
                small += string(cnt_m - 1, '0');
            }
            cnt_m = 0;
            small.push_back('5');
        }
    }
    if(cnt_m > 0){
        small.push_back('1');
        small += string(cnt_m - 1, '0');
    }
    cout << big << "\n" << small;

    return 0;
}