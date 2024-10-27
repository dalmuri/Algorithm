#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, t, p;
    vector<int> people(6);
    cin >> n;
    for(int i = 0; i < 6; i++) cin >> people[i];
    cin >> t >> p;

    cout << accumulate(people.begin(), people.end(), 0, [&t](int acc, int e){ return acc + e / t + min(1, e % t); }) << "\n";
    cout << n / p << " " << n % p;

    return 0;
}