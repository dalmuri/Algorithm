#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void turn(int idx, string& bulbs){
    for(int i = idx; i < bulbs.size(); i+=idx) bulbs[i] = (bulbs[i] == 'Y') ? 'N' : 'Y';
}

int main(){
    FASTIO

    string bulbs;
    cin >> bulbs;
    bulbs = " " + bulbs;

    int answer = 0;
    for(int i = 1; i < bulbs.size(); ++i){
        if(bulbs[i] == 'Y'){
            turn(i, bulbs);
            answer++;
        }
    }

    cout << answer;

    return 0;
}