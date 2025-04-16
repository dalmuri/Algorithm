#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    double answer = 0.0;
    int max_drink = 0;
    for(int i = 0; i < n; ++i){
        int drink;
        cin >> drink;

        answer += (double)drink / 2.0;
        max_drink = max(max_drink, drink);
    }

    answer += (double)max_drink / 2.0;
    cout << answer;

    return 0;
}