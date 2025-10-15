#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(n);
    long long answer = 0ll;
    for(int i = 0, b; i < n; ++i){
        cin >> arr[i] >> b;
        answer += b;
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; ++i){
        answer += (long long)arr[i] * (i + 1);
    }

    cout << answer;

    return 0;
}