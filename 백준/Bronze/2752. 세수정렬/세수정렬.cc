#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> nums(3);
    for(int i = 0; i < 3; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    for(int i = 0; i < 3; i++) cout << nums[i] << " ";

    return 0;
}