#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;

void push_switch(int idx, vector<bool>& bulbs){
    if(idx > 0) bulbs[idx - 1] = !bulbs[idx - 1];
    bulbs[idx] = !bulbs[idx];
    if(idx + 1 < n) bulbs[idx + 1] = !bulbs[idx + 1];
}

int calc(vector<bool> bulbs, vector<bool>& result){
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(bulbs[i - 1] != result[i - 1]){
            push_switch(i, bulbs);
            cnt++;
        }
    }

    if(bulbs[n - 1] != result[n - 1]) return -2;
    return cnt;
}

int main(){
    FASTIO

    cin >> n;

    vector<bool> bulbs(n, false);
    for(int i = 0; i < n; i++){
        char on;
        cin >> on;

        if(on == '1') bulbs[i] = true;
    }

    vector<bool> result(n, false);
    for(int i = 0; i < n; i++){
        char on;
        cin >> on;

        if(on == '1') result[i] = true;
    }

    int answer1 = calc(bulbs, result);

    push_switch(0, bulbs);
    int answer2 = calc(bulbs, result) + 1;

    if(answer1 < 0 && answer2 < 0) cout << "-1";
    else if(answer1 < 0) cout << answer2;
    else if(answer2 < 0) cout << answer1;
    else cout << min(answer1, answer2);

    return 0;
}