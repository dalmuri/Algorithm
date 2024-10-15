#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;

void dfs(int now, int cnt, vector<bool>& nums){
    if(cnt == m){
        for(int i = 1; i <= n; i++){
            if(nums[i]) cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if(n - now + 1 + cnt < m) return;

    for(int i = now; i <= n; i++){
        nums[i] = true;
        dfs(i + 1, cnt + 1, nums);
        nums[i] = false;
    }
}

int main(){
    FASTIO

    cin >> n >> m;

    vector<bool> nums(n + 1, false);
    dfs(1, 0, nums);

    return 0;
}