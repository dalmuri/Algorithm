#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    stack<int> idxs;
    long long answer = 0ll;
    for(int i = 0; i < n; ++i){
        if(!idxs.empty() && idxs.top() <= nums[i]){
            answer += nums[i] - idxs.top();
            while(!idxs.empty() && idxs.top() <= nums[i]) idxs.pop();
        }
        idxs.push(nums[i]);
    }
    if(idxs.size() > 1){
        int low = idxs.top();
        while(idxs.size() > 1) idxs.pop();
        answer += idxs.top() - low;
    }

    cout << answer;

    return 0;
}