#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<long long> loss(n);
    for(int i = 0; i < n; ++i) cin >> loss[i];

    sort(loss.begin(), loss.end());

    int l = 0, r = n - 1;
    long long answer = 0ll;
    if(n & 1){
        r = n - 2;
        answer = loss.back();
    }

    while(l < r){
        answer = max(answer, loss[l] + loss[r]);
        ++l;
        --r;
    }

    cout << answer;

    return 0;
}