#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<long long> scores(n);
    for(int i = 0; i < n; ++i) cin >> scores[i];

    for(int i = 1; i < n; ++i) scores[i] += scores[i - 1];

    sort(scores.rbegin(), scores.rend());

    cout << accumulate(scores.begin(), scores.begin() + k, 0ll);

    return 0;
}