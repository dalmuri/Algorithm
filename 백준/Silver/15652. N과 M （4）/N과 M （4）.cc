#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;

void dfs(int now, int cnt, vector<int>& nums){
    if(cnt == m){
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < nums[i]; j++){
                cout << i << " ";
            }
        }
        cout << "\n";
        return;
    }

    for(int i = now; i <= n; i++){
        nums[i]++;
        dfs(i, cnt + 1, nums);
        nums[i]--;
    }
}

int main(){
    FASTIO

    cin >> n >> m;

    vector<int> nums(n + 1, 0);
    dfs(1, 0, nums);

    return 0;
}