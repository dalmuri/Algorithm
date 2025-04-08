#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string a, b;
    cin >> a >> b;

    int min_diff = 51;
    for(int start = 0; start <= b.size() - a.size(); ++start){
        int diff = 0;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[start + i]) ++diff;
        }

        min_diff = min(min_diff, diff);
    }

    cout << min_diff;

    return 0;
}