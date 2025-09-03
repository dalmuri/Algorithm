#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, marble, mini = 1'000'000'001, maxi = 0;
    cin >> n;

    while(n--){
        cin >> marble;

        mini = min(mini, marble);
        maxi = max(maxi, marble);
    } 

    cout << ((maxi - mini) << 1);

    return 0;
}