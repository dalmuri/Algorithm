#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool contains(long long num, vector<long long>& arr){
    int idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
    if(idx < arr.size() && arr[idx] == num) return true;
    return false;
}

bool dfs(vector<long long> arr, vector<long long>& result){
    if(arr.size() == result.size()) return true;

    long long now = result.back();

    if(now % 3 == 0 && contains(now / 3, arr)){
        result.push_back(now / 3);
        return dfs(arr, result);
    }
    if(contains(now * 2, arr)){
        result.push_back(now * 2);
        return dfs(arr, result);
    }

    return false;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<long long> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; ++i){
        vector<long long> answer = {arr[i]};
        if(dfs(arr, answer)){
            for(int j = 0; j < n; ++j) cout << answer[j] << " ";
            break;
        }
    }

    return 0;
}