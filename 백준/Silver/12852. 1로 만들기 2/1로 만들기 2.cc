#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int inf = 987654321;

    int n;
    cin >> n;

    vector<int> cnt(n + 1);
    cnt[1] = 0;
    for(int i = 2; i <= n; i++){
        cnt[i] = cnt[i - 1] + 1;
        if(i % 2 == 0) cnt[i] = min(cnt[i], cnt[i / 2] + 1);
        if(i % 3 == 0) cnt[i] = min(cnt[i], cnt[i / 3] + 1);
    }

    cout << cnt[n] << "\n";
    
    int now = n;
    while(now >= 1){
        cout << now << " ";

        int next1 = (now % 2 == 0 && cnt[now] - 1 == cnt[now / 2]) ? now / 2 : inf;
        int next2 = (now % 3 == 0 && cnt[now] - 1 == cnt[now / 3]) ? now / 3 : inf;

        now = min({now - 1, next1, next2});
    }

    return 0;
}