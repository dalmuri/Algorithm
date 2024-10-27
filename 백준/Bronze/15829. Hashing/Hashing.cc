#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int r = 31, m = 1234567891;
    int l;
    cin >> l;

    long long h = 0ll;
    for(int i = 0; i < l; i++){
        char c;
        cin >> c;

        long long tmp = c - 'a' + 1;
        for(int j = 0; j < i; j++) tmp = (tmp * r) % m;

        h = (h + tmp) % m;
    }

    cout << h;

    return 0;
}