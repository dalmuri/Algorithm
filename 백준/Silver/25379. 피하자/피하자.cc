#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int count_odd;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        
        if(arr[i] & 1) ++count_odd;
    }

    long long left_odd = 0ll, left_even = 0ll;
    int cnt_odd = 0, cnt_even = 0;

    for(int i = 0; i < n; ++i) if(arr[i] & 1) left_odd += i - cnt_odd++;
    for(int i = 0; i < n; ++i) if((arr[i] & 1) == 0) left_even += i - cnt_even++;

    cout << min(left_odd, left_even);

    return 0;
}