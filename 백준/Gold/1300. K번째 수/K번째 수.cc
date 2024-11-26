#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, k;

long long cnt(int num){
    long long res = 0ll;
    for(int i = 1; i <= num && i <= n; i++){
        res += min(num / i, n);
    }

    return res;
}

int main(){
    FASTIO

    cin >> n >> k;

    int left = 1, right = k;
    long long answer = right;
    while(left <= right){
        int mid = (left + right) / 2;

        if(cnt(mid) >= k){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}