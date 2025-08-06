#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<long long> exp(n);
    for(int i = 0; i < n; ++i) cin >> exp[i];

    sort(exp.begin(), exp.end());

    for(int i = 1; i < n; ++i) exp[i] += exp[i - 1];

    long long answer = 0ll;
    for(int i = 0; i < k; ++i) answer += exp.back() - exp[i];

    cout << answer;

    return 0;
}