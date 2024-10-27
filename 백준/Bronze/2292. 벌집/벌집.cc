#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 1;
    int sum = 1;
    while(sum < n){
        sum += answer * 6;
        answer++;
    }

    cout << answer;

    return 0;
}