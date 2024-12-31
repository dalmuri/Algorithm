#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<double> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    double answer = 0;
    for(int i = 1; i < n; i++){
        if(arr[i - 1] > 1) arr[i] *= arr[i - 1];

        answer = max(answer, arr[i]);
    }

    cout << fixed;
    cout.precision(3);
    cout << answer;

    return 0;
}