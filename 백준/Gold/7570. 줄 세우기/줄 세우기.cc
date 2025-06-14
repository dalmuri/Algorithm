#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0);
    int lis = 1;
    for(int i = 0, child; i < n; ++i){
        cin >> child;
        cnt[child] = cnt[child - 1] + 1;

        lis = max(lis, cnt[child]);
    }

    cout << n - lis;

    return 0;
}