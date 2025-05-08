#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        int sejun = 0, sebi = 0;
        for(int i = 0; i < n; ++i){
            int s;
            cin >> s;

            sejun = max(sejun, s);
        }

        for(int i = 0; i < m; ++i){
            int b;
            cin >> b;

            sebi = max(sebi, b);
        }

        if(sejun < sebi) cout << "B\n";
        else cout << "S\n";
    }

    return 0;
}