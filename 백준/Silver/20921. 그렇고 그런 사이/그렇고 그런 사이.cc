#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<bool> visited(n + 1, false);
    int max_num = n;
    while(k > 0){
        int tmp = k + 1;
        if(tmp > max_num) tmp = max_num--;

        cout << tmp << " ";
        visited[tmp] = true;
        k -= tmp - 1;
    }

    for(int i = 1; i <= n; ++i){
        if(!visited[i]) cout << i << " ";
    }

    return 0;
}