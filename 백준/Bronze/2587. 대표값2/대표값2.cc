#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> arr(5);
    for(int i = 0; i < 5; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    cout << accumulate(arr.begin(), arr.end(), 0) / 5 << "\n" << arr[2];

    return 0;
}