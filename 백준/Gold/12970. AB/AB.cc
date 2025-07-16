#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    if(k <= n / 2 * (n - n / 2)){
        int a = n - n / 2;
        int right_b = k / a;
        int mid_b_pos = k % a;
        int left_b = max(0, n - a - right_b - 1);

        cout << string(left_b, 'B') + string(mid_b_pos, 'A') + (a + right_b == n ? "" : "B") + string(a - mid_b_pos, 'A') + string(right_b, 'B');
    }
    else{
        cout << "-1";
    }

    return 0;
}