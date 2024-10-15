#include <string>
#include <iostream>
#include <vector>
#include <map>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;

void dfs(vector<int>& output, vector<vector<int>>& nums){
    if(output.size() == m){
        for(int out : output) cout << out << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i][1] <= 0) continue;

        output.push_back(nums[i][0]);
        nums[i][1]--;

        dfs(output, nums);

        output.pop_back();
        nums[i][1]++;
    }
}

int main(){
    FASTIO

    cin >> n >> m;

    map<int, int> dict;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        dict[num]++;
    }

    vector<vector<int>> nums;
    for(auto iter = dict.begin(); iter != dict.end(); iter++){
        nums.push_back({(*iter).first, (*iter).second});
    }

    vector<int> output;

    dfs(output, nums);

    return 0;
}