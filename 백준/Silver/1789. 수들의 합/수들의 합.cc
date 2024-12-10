#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    long long s;
    cin >> s;

    long long n = 1;
    for(; n * (n + 1) <= 2 * s; n++);

    cout << n - 1;

    return 0;
}