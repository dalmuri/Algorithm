#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;

    map<int, int> exists;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        exists[num]++;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        if(exists[num] > 0) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}