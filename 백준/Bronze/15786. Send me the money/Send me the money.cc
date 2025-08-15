#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    while(m--){
        string word;
        cin >> word;

        int idx = 0;
        for(int i = 0; i < word.size() && idx < n; ++i){
            if(word[i] == s[idx]) idx++;
        }

        cout << (idx < n ? "false\n" : "true\n");
    }

    return 0;
}