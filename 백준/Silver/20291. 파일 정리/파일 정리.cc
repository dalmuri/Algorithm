#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    map<string, int> extension;
    for(int i = 0; i < n; i++){
        string file;
        cin >> file;

        int idx = file.find('.');
        extension[file.substr(idx + 1)]++;
    }

    for(auto iter = extension.begin(); iter != extension.end(); iter++){
        cout << iter->first << " " << iter->second << "\n";
    }

    return 0;
}