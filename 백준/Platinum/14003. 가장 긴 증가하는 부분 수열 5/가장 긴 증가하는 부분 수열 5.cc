#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> process;
    vector<int> idxs(n);
    for(int i = 0; i < n; i++){
        auto iter = lower_bound(process.begin(), process.end(), arr[i]);
        idxs[i] = iter - process.begin();
        if(iter == process.end()) process.push_back(arr[i]);
        else *iter = arr[i];
    }

    vector<int> lis(process.size());
    int idx = process.size() - 1;
    for(int i = n - 1; i >= 0; i--){
        if(idxs[i] == idx){
            lis[idx] = arr[i];
            idx--;
        }
    }

    cout << lis.size() << "\n";
    for(int i = 0; i < lis.size(); i++) cout << lis[i] << " ";

    return 0;
}