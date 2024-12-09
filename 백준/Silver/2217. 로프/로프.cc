#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> ropes(n);
    for(int i = 0; i < n; i++) cin >> ropes[i];

    sort(ropes.begin(), ropes.end());

    int answer = 0;
    for(int i = 0; i < n; i++){
        answer = max(answer, ropes[i] * (n - i));
    }

    cout << answer;

    return 0;
}