#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int sugar3[] = {0, 2, 4, 1, 3, 0, 2, 4, 1, 3};

    long long n;
    cin >> n;

    long long answer = -1ll;
    if(n >= sugar3[n % 10] * 3) answer = sugar3[n % 10] + (n - sugar3[n % 10] * 3) / 5;

    cout << answer;

    return 0;
}