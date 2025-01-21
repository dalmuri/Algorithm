#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, l;
    cin >> n >> l;

    vector<int> pos(n);
    for(int i = 0; i < n; i++) cin >> pos[i];

    sort(pos.begin(), pos.end());

    int answer = 1;
    int start = pos[0];
    for(int i = 1; i < n; i++){
        if(pos[i] < start + l) continue;

        start = pos[i];
        answer++;
    }

    cout << answer;

    return 0;
}