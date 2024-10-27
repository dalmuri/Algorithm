#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int cnt2 = 0, cnt5 = 0;
    for(int i = 1; i <= n; i++){
        int num = i;
        while(num % 2 == 0){
            cnt2++;
            num /= 2;
        }

        num = i;
        while(num % 5 == 0){
            cnt5++;
            num /= 5;
        }
    }

    cout << min(cnt2, cnt5);

    return 0;
}