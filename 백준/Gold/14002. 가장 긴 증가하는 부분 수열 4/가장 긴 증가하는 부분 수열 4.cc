#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<int> lis;
    vector<int> idxs(n);
    for(int i = 0; i < n; i++){
        auto iter = lower_bound(lis.begin(), lis.end(), nums[i]);
        idxs[i] = iter - lis.begin();
        if(iter == lis.end()) lis.push_back(nums[i]);
        else *iter = nums[i];
        
    }

    vector<int> seq;
    int idx = lis.size() - 1;
    for(int i = idxs.size() - 1; i >= 0 && idx >= 0; i--){
        if(idxs[i] == idx){
            seq.push_back(nums[i]);
            idx--;
        }
    }
    
    cout << seq.size() << "\n";
    for(int i = seq.size() - 1; i >= 0; i--) cout << seq[i] << " ";

    return 0;
}