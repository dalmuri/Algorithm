#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, cnt_b;

int cnt(char color){
    if(color == 'B') return cnt_b;
    else return n - cnt_b;
}

int main(){
    FASTIO

    cin >> n;

    vector<char> balls(n);
    for(int i = 0; i < n; ++i){
        cin >> balls[i];

        if(balls[i] == 'B') cnt_b++;
    }

    int left_same_cnt = 1;
    for(int i = 1; i < n; ++i, ++left_same_cnt){
        if(balls[i] != balls[0]) break;
    }

    int right_same_cnt = 1;
    for(int i = n - 2; i >= 0; --i, ++right_same_cnt){
        if(balls[i] != balls[n - 1]) break;
    }

    cout << min({cnt(balls[0]) - left_same_cnt, cnt(balls[n - 1]) - right_same_cnt, cnt('B'), cnt('R')});

    return 0;
}