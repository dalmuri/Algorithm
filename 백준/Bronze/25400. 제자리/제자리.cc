#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int number = 1, answer = 0;
    for(int i = 0; i < n; ++i){
        int card;
        cin >> card;

        if(card == number) number++;
        else answer++;
    }

    cout << answer;

    return 0;
}