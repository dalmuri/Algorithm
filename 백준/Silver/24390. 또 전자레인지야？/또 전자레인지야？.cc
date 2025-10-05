#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string timer;
    cin >> timer;

    int min = stoi(timer.substr(0, 2));
    int sec = stoi(timer.substr(3));
    if(sec >= 30) sec -= 30;

    cout << 1 + min / 10 + min % 10 + sec / 10;

    return 0;
}