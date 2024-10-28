#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int k, n;
    cin >> k >> n;

    vector<int> lines(k);
    for(int i = 0; i < k; i++) cin >> lines[i];

    long long left = 1;
    long long right = INT_MAX;
    long long answer = 1;
    while(left <= right){
        long long mid = (left + right) / 2;

        if(accumulate(lines.begin(), lines.end(), 0ll, [&](long long acc, int line){ return acc + line / mid; }) >= n){
            left = mid + 1;
            answer = mid;
        }
        else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}