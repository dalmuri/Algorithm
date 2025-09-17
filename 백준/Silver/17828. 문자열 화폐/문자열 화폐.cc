#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, x;
    cin >> n >> x;

    if(x < n || 26 * n < x) cout << "!";
    else{
        int cnt_z = (x - n) / 25;
        int cnt_a = n - cnt_z;
        string mid = "";

        if(cnt_a + cnt_z * 26 < x){
            cnt_a--;
            mid = string(1, 'A' + x - cnt_a - cnt_z * 26 - 1);
        }

        cout << string(cnt_a, 'A') + mid + string(cnt_z, 'Z');
    }

    return 0;
}