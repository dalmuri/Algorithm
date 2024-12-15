#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string s;
    cin >> s;

    array<int, 2> cnt{0, 0};
    cnt[s[0] - '0']++;
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == s[i]) continue;

        cnt[s[i] - '0']++;
    }

    cout << min(cnt[0], cnt[1]);

    return 0;
}