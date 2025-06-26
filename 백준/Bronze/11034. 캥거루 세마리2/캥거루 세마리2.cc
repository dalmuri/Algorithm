#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b, c;
    while(cin >> a){
        cin >> b >> c;

        cout << max(b - a, c - b) - 1 << "\n";
    }

    return 0;
}