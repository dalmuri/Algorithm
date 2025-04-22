#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; ++i) cout << nums[i] << "\n";

    return 0;
}