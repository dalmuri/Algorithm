#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> chains(n);
    for(int i = 0; i < n; ++i) cin >> chains[i];

    sort(chains.begin(), chains.end());
    int left = 0, right = n - 1, answer = 0;
    while(left < right){
        if(--chains[left] < 1) left++;

        right--;
        answer++;
    }

    cout << answer;

    return 0;
}