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

        string start, end;
        cin >> start >> end;

        int cnt_to_B = 0, cnt_to_W = 0;
        for(int i = 0; i < n; ++i){
            if(start[i] == 'W' && end[i] == 'B') cnt_to_B++;
            else if(start[i] == 'B' && end[i] == 'W') cnt_to_W++;
        }

        cout << max(cnt_to_B, cnt_to_W) << "\n";
    }

    return 0;
}