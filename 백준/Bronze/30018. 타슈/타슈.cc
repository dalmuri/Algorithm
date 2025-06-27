#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int answer = 0;
    for(int i = 0, b; i < n; ++i){
        cin >> b;

        if(a[i] > b) answer += a[i] - b;
    }

    cout << answer;

    return 0;
}