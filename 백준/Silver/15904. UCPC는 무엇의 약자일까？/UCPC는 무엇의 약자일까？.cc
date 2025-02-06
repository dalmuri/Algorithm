#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    getline(cin, str);

    char to_find[] = {'U', 'C', 'P', 'C'};
    int idx = 0;

    for(char c : str){
        if(c == to_find[idx]){
            idx++;
            if(idx == 4) break;
        }
    }

    if(idx == 4) cout << "I love UCPC";
    else cout << "I hate UCPC";

    return 0;
}