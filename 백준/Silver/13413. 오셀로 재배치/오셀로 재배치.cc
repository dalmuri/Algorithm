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

        vector<char> initial(n);
        for(int i = 0; i < n; ++i) cin >> initial[i];

        int cnt_to_B = 0, cnt_to_W = 0;
        for(int i = 0; i < n; ++i){
            char obj;
            cin >> obj;

            if(initial[i] != obj){
                if(initial[i] == 'W') cnt_to_B++;
                else cnt_to_W++;
            }
        }

        cout << max(cnt_to_B, cnt_to_W) << "\n";
    }

    return 0;
}