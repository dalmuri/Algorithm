#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> arr(10);
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 10; i++) cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        cout << arr[2] << "\n";
    }

    return 0;
}