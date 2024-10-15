#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    vector<int> perm(n - m, 0);
    for(int i = 1; i <= m; i++) perm.push_back(i);

    vector<vector<int>> all;
    do{
        vector<int> tmp;
        for(int i = 1; i <= m; i++){
            tmp.push_back(nums[find(perm.begin(), perm.end(), i) - perm.begin()]);
        }
        all.push_back(tmp);
    }while(next_permutation(perm.begin(), perm.end()));

    sort(all.begin(), all.end());

    for(vector<int> vec : all){
        for(int num : vec) cout << num << " ";
        cout << "\n";
    }

    return 0;
}