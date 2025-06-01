#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> books(n);
    for(int i = 0; i < n; ++i) cin >> books[i];

    int big = 0, answer = 0;
    for(int i = 0; i < n; ++i){
        if(big > books[i]) answer = max(answer, books[i]);
        else big = books[i];
    }

    cout << answer;

    return 0;
}