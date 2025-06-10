#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string s, t;
    while(cin >> s){
        cin >> t;

        int idx = 0;
        for(int i = 0; i < t.size() && idx < s.size(); ++i){
            if(s[idx] == t[i]) idx++;
        }

        if(idx >= s.size()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}