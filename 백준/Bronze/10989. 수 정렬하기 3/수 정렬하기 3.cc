#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> arr(10001);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[num]++;
    }

    for(int i = 1; i < 10001; i++){
        for(int j = 0; j < arr[i]; j++) cout << i << "\n";
    }

    return 0;
}