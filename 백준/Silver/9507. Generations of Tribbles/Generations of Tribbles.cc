#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

long long koong[68];

int main(){
    FASTIO

    koong[0] = 1;
    koong[1] = 1;
    koong[2] = 2;
    koong[3] = 4;
    for(int i = 4; i < 68; i++){
        koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << koong[n] << "\n";
    }

    return 0;
}