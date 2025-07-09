#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int p, n;
    cin >> p >> n;

    vector<int> fatigue(n);
    for(int i = 0; i < n; ++i) cin >> fatigue[i];

    sort(fatigue.begin(), fatigue.end());

    int answer = 0;
    for(int i = 0; i < n && p < 200; ++i){
        p += fatigue[i];
        answer++;
    }

    cout << answer;

    return 0;
}