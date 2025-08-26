#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void swap0(string& num){
    for(int i = 1; i < num.size(); ++i){
        if(num[i] != '0'){
            swap(num[0], num[i]);
            return;
        }
    }
}

int main(){
    FASTIO

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<int> nums(n);
        for(int i = 0; i < n; ++i) cin >> nums[i];

        sort(nums.begin(), nums.end());

        string a = "", b = "";
        for(int i = 0; i < n; ++i){
            if(i & 1) a.push_back(nums[i] + '0');
            else b.push_back(nums[i] + '0');
        }

        if(a[0] == '0') swap0(a);
        if(b[0] == '0') swap0(b);

        if(a.size() < b.size() && a[0] < b[0]) swap(a[0], b[0]);
        cout << (stoi(a) + stoi(b)) << "\n";
    }

    return 0;
}