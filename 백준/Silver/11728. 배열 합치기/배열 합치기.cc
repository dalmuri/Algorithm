#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    int x = 0, y = 0;
    while(x < n || y < m){
        if(x == n) cout << b[y++] << " ";
        else if(y == m) cout << a[x++] << " ";
        else if(a[x] < b[y]) cout << a[x++] << " ";
        else cout << b[y++] << " ";
    }

    return 0;
}