#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int to_even(vector<int>& arr){
    int result = 0;
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] & 1){
            arr[i]--;
            result++;
        }
    }

    return result;
}

int cut_in_half(vector<int>& arr){
    for(int i = 0; i < arr.size(); ++i) arr[i] /= 2;
    return 1;
}

bool is_all_zero(vector<int>& arr){
    for(int i = 0; i < arr.size(); ++i) if(arr[i]) return false;
    return true;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int answer = 0;
    while(!is_all_zero(arr)){
        answer += to_even(arr);
        if(is_all_zero(arr)) break;
        answer += cut_in_half(arr);
    }

    cout << answer;

    return 0;
}