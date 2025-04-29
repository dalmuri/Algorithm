#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.rbegin(), nums.rend());

    cout << accumulate(nums.begin(), nums.begin() + k, 0) - k * (k - 1) / 2;

    return 0;
}