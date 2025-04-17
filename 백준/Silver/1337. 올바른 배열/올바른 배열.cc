#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int cnt_need(int idx, vector<int>& arr){
    int start = arr[idx];
    int cnt = 4;
    for(int i = idx + 1; i < min(idx + 5, n); ++i){
        if(start < arr[i] && arr[i] < start + 5) --cnt;
    }

    return cnt;
}

int main(){
    FASTIO

    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int answer = 4;
    for(int i = 0; i < n; ++i) answer = min(answer, cnt_need(i, arr));

    cout << answer;

    return 0;
}