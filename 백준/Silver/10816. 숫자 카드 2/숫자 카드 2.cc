#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;

    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        cnt[num]++;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;

        cout << cnt[num] << " ";
    }

    return 0;
}