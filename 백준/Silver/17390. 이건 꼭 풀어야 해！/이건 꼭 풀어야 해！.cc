#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    sort(arr.begin() + 1, arr.end());
    for(int i = 1; i <= n; ++i) arr[i] += arr[i - 1];

    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;

        cout << arr[r] - arr[l - 1] << "\n";
    }

    return 0;
}