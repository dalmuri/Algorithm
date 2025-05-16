#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void calc(vector<int>& sticks, int size, long long& answer){
    if(size == 1) return;
    
    sort(sticks.begin(), sticks.begin() + size);

    for(int left = 0, right = (size & 1) ? size - 2 : size - 1; left < right; ++left, --right){
        answer += sticks[left] * sticks[right];
        sticks[left] += sticks[right];
    }

    if(size & 1) sticks[size / 2] = sticks[size - 1];

    calc(sticks, (size + 1) / 2, answer);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> sticks(n);
    for(int i = 0; i < n; ++i) cin >> sticks[i];

    long long answer = 0ll;
    calc(sticks, n, answer);

    cout << answer;

    return 0;
}