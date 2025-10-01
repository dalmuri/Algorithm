#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> rooms(n + 1, 0);
    for(int i = 0, k, s, e; i < m; ++i){
        cin >> k >> s >> e;

        if(rooms[k] <= s){
            cout << "YES\n";
            rooms[k] = e;
        }
        else cout << "NO\n";
    }

    return 0;
}