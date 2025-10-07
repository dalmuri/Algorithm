#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, k;
bool check(int dist, vector<int>& positions){
    for(int i = 1, prev = 0, cnt = 1; i < k; ++i){
        if(positions[i] - positions[prev] >= dist){
            prev = i;
            if(++cnt >= m) return true;
        }
    }

    return false;
}

int main(){
    FASTIO

    cin >> n >> m >> k;

    vector<int> positions(k);
    for(int i = 0; i < k; ++i) cin >> positions[i];

    int l = 0, r = positions.back() - positions.front(), answer = 1;
    while(l <= r){
        int mid = (l + r) / 2;

        if(check(mid, positions)) l = (answer = mid) + 1;
        else r = mid - 1;
    }

    cout << 1;
    for(int i = 1, prev = 0, cnt = 1; i < k; ++i){
        if(cnt < m && positions[i] - positions[prev] >= answer) cnt++, prev = i, cout << 1;
        else cout << 0;
    }

    return 0;
}