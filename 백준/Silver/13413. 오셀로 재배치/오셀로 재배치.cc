#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        string start, end;
        cin >> n >> start >> end;

        int diff = 0, startB = 0, endB = 0;
        for(int i = 0; i < n; ++i){
            diff += start[i] != end[i];
            startB += start[i] == 'B';
            endB += end[i] == 'B';
        }
        
        int diffB = abs(endB - startB);
        cout << (diff - diffB) / 2 + diffB << "\n";
    }

    return 0;
}