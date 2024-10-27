#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int cnt2 = 0, cnt5 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j % 2 == 0; j /= 2) cnt2++;
        for(int j = i; j % 5 == 0; j /= 5) cnt5++;
    }

    cout << min(cnt2, cnt5);

    return 0;
}