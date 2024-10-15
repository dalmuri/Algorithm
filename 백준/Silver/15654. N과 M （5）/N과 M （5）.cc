#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<int> nums;

void dfs(vector<bool>& used, vector<int>& output){
    if(output.size() == m){
        for(int out : output) cout << out << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(used[i]) continue;

        output.push_back(nums[i]);
        used[i] = true;

        dfs(used, output);

        output.pop_back();
        used[i] = false;
    }
}

int main(){
    FASTIO

    cin >> n >> m;

    nums = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    vector<bool> used(n, false);
    vector<int> output;

    dfs(used, output);

    return 0;
}