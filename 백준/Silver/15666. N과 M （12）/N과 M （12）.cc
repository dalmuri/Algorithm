#include <string>
#include <iostream>
#include <vector>
#include <set>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;

void dfs(int idx, int cnt, vector<int>& output, vector<int>& nums){
    if(cnt == m){
        for(int i = 0; i < output.size(); i++){
            for(int j = 0; j < output[i]; j++) cout << nums[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i < nums.size(); i++){
        output[i]++;

        dfs(i, cnt + 1, output, nums);

        output[i]--;
    }
}

int main(){
    FASTIO

    cin >> n >> m;
    set<int> s;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    vector<int> nums;
    for(auto iter = s.begin(); iter != s.end(); iter++){
        nums.push_back(*iter);
    }

    vector<int> output(nums.size(), 0);

    dfs(0, 0, output, nums);

    return 0;
}