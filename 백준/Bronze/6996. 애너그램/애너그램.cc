#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;

        cout << a << " & " << b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a == b) cout << " are anagrams.\n";
        else cout << " are NOT anagrams.\n";
    }

    return 0;
}