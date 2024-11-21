#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> lis;
    for(int i = 0; i < n; i++){
        auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
        if(iter == lis.end()) lis.push_back(arr[i]);
        else (*iter) = arr[i];
    }

    cout << lis.size();

    return 0;
}