#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        
        set<int> note1;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;

            note1.insert(num);
        }

        cin >> m;
        for(int i = 0; i < m; i++){
            int num;
            cin >> num;

            if(note1.count(num) > 0) cout << "1\n";
            else cout << "0\n";
        }
    }

    return 0;
}