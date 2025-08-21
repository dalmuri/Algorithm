#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int bowls[50'001];

int main(){
    FASTIO

    int n, bowl;
    cin >> n;

    while(n--){
        cin >> bowl;
        bowls[bowl]++;
    }

    cout << *max_element(bowls, bowls + 50'001);

    return 0;
}