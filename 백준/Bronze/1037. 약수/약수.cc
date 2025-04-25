#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> divisors(n);
    for(int i = 0; i < n; ++i) cin >> divisors[i];

    cout << *min_element(divisors.begin(), divisors.end()) * *max_element(divisors.begin(), divisors.end());

    return 0;
}