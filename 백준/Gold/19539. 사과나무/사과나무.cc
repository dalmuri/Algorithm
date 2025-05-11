#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int q2 = 0;
    long long sum = 0ll;
    for(int i = 0; i < n; ++i){
        int height;
        cin >> height;

        sum += height;
        q2 += height / 2;
    }

    if(sum % 3ll == 0ll && q2 >= sum / 3) cout << "YES";
    else cout << "NO";

    return 0;
}