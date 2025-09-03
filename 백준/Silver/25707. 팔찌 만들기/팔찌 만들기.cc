#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> marbles(n);
    for(int i = 0; i < n; ++i) cin >> marbles[i];

    cout << ((*max_element(marbles.begin(), marbles.end()) - *min_element(marbles.begin(), marbles.end())) << 1);

    return 0;
}