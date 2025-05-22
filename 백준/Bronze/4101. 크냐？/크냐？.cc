#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0) break;

        cout << (a > b ? "Yes\n" : "No\n");
    }

    return 0;
}