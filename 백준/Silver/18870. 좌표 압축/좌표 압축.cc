#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> nums(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums[i] = {x, i};
    }

    sort(nums.begin(), nums.end());

    int cnt = 0;
    vector<int> answer(n, 0);
    for(int i = 1; i < n; i++){
        if(nums[i].first > nums[i - 1].first){
            cnt++;
        }

        answer[nums[i].second] = cnt;
    }

    for(int ans : answer) cout << ans << " ";

    return 0;
}