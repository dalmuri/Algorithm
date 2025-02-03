#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    for(int i = 1; true; i++){
        int l, p, v;
        cin >> l >> p >> v;

        if(l == 0 && p == 0 && v == 0) break;

        int answer = 0;
        while(v > 0){
            answer += min({l, p, v});
            v -= p;
        }

        cout << "Case " << i << ": " << answer << "\n";
    }

    return 0;
}