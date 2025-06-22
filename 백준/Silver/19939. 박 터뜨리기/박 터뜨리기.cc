#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    n -= k * (k + 1) / 2;
    cout << (n < 0 ? -1 : n % k ? k : k - 1);

    return 0;
}