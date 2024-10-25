#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, x;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cin >> x;

    sort(arr.begin(), arr.end());
    int answer = 0;
    for(int i = 0; i + 1 < n; i++){
        int a1 = arr[i];
        if(a1 < x && *lower_bound(arr.begin() + i + 1, arr.end(), x - a1) == x - a1) answer++;
    }

    cout << answer;

    return 0;
}