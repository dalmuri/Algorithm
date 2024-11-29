#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, q;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cin >> q;
    for(int i = 0; i < q; i++){
        int t, k;
        cin >> t >> k;
        if(t == 1){
            if(tree[k].size() > 1) cout << "yes\n";
            else cout << "no\n";
        }
        else cout << "yes\n";
    }

    return 0;
}