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
            int now = idxs.top();
            answer += nums[i] - idxs.top();
            while(!idxs.empty() && idxs.top() <= nums[i]) idxs.pop();
        }
        idxs.push(nums[i]);
    }
    while(idxs.size() > 1){
        int top = idxs.top();
        idxs.pop();
        answer += idxs.top() - top;
    }

    cout << answer;

    return 0;
}