#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    
    nums.push_back(4001);
    vector<int> modes = {};
    int max_cnt = 0;
    int cnt = 0;
    for(int i = 0; i < n + 1; i++){
        if(i > 0 && nums[i] != nums[i - 1]){
            if(max_cnt < cnt){
                max_cnt = cnt;
                modes = {nums[i - 1]};
            }
            else if(max_cnt == cnt) modes.push_back(nums[i - 1]);
            
            cnt = 0;
        }

        cnt++;
    }
    nums.pop_back();

    cout << (int)round((double)accumulate(nums.begin(), nums.end(), 0) / n) << "\n";
    cout << nums[n / 2] << "\n";
    cout << (modes.size() > 1 ? modes[1] : modes[0]) << "\n";
    cout << nums[n - 1] - nums[0];

    return 0;
}