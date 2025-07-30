#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int lowest;
    cin >> lowest;
    cout << "0 ";
    for(int i = 1, last = 0, num; i < n; ++i){
        cin >> num;
        lowest = min(lowest, num);

        last = max(last, num - lowest);
        cout << last << " ";
    }

    return 0;
}