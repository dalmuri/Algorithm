#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int l = 0, r = 0, answer = 2'000'000'001;
    while(r < n - 1){
        if(arr[r] - arr[l] < m) r++;
        else if(l >= r){
            answer = min(answer, arr[r] - arr[l]);
            r++;
        }
        else{
            answer = min(answer, arr[r] - arr[l]);
            l++;
        }
    }

    while(l < n){
        if(arr[r] - arr[l] < m) break;

        answer = min(answer, arr[r] - arr[l]);
        l++;
    }

    cout << answer;

    return 0;
}