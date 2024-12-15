#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string n;
    cin >> n;

    sort(n.rbegin(), n.rend());
    int sum = accumulate(n.begin(), n.end(), 0, [](int acc, char e){ return acc + e - '0'; });
    if(n.back() == '0' && sum % 3 == 0) cout << n;
    else cout << -1;

    return 0;
}