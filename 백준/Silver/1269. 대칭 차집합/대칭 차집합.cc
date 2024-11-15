#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> cnt;
    int answer = 0;
    for(int i = 0; i < n + m; i++){
        int e;
        cin >> e;

        cnt[e]++;
        if(cnt[e] == 1) answer++;
        else answer--;
    }

    cout << answer;

    return 0;
}