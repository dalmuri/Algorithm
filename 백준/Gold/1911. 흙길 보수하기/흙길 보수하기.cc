#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> pools(n);
    for(int i = 0; i < n; ++i) cin >> pools[i].first >> pools[i].second;

    sort(pools.begin(), pools.end());

    int last = 0;
    int answer = 0;
    for(int i = 0; i < n; ++i){
        int length = pools[i].second - pools[i].first;
        if(pools[i].first < last){ // 겹침
            length = pools[i].second - last;
            if(length <= 0) continue;
        }

        answer += length / l + min(1, length % l);
        last = pools[i].second;
        if(length % l) last += l - length % l;
    }
    
    cout << answer;

    return 0;
}