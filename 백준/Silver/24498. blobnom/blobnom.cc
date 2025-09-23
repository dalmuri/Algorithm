#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> tower(n);
    for(int i = 0; i < n; ++i) cin >> tower[i];

    long long answer = max(tower.front(), tower.back());
    for(int i = 1; i < n - 1; ++i){
        answer = max(answer, (long long)tower[i] + min(tower[i - 1], tower[i + 1]));
    }

    cout << answer;

    return 0;
}