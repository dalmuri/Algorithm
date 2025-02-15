#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int abc[3];
    for(int i = 0; i < 3; i++) cin >> abc[i];

    sort(abc, abc + 3);

    cout << abc[1];

    return 0;
}