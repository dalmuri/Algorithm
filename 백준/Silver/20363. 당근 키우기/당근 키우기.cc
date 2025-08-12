#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int x, y;
    cin >> x >> y;

    cout << x + y + min(x, y) / 10;

    return 0;
}