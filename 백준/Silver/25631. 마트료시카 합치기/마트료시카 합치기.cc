#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    unordered_map<int, int> cnt;
    int answer = 0;
    for(int i = 0, num; i < n; ++i){
        cin >> num;

        answer = max(answer, ++cnt[num]);
    }

    cout << answer;

    return 0;
}