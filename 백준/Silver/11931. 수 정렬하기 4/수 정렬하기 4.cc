#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.rbegin(), arr.rend());

    for(int i = 0; i < n; i++) cout << arr[i] << "\n";

    return 0;
}