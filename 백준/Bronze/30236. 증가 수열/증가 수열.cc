#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        int now = 1;
        for(int i = 0; i < n; ++i, ++now){
            if(a[i] == now) now++;
        }

        cout << now - 1 << "\n";
    }

    return 0;
}