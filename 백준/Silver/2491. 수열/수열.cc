#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;



int main(){
    FASTIO

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    int answer = 1;
    for(int i = 1; i < n; i++){
        if(arr[i - 1] <= arr[i]) inc[i] = inc[i - 1] + 1;
        if(arr[i - 1] >= arr[i]) dec[i] = dec[i - 1] + 1;

        answer = max({answer, inc[i], dec[i]});
    }

    cout << answer;

    return 0;
}