#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0;
    unordered_map<int, int> cnt;
    for(int i = 0, h; i < n; ++i){
        cin >> h;

        if(++cnt[h] <= 2) answer++;
    }

    cout << answer;

    return 0;
}