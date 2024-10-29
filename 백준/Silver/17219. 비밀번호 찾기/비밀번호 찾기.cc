#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> passwords;
    for(int i = 0; i < n; i++){
        string website, password;
        cin >> website >> password;

        passwords[website] = password;
    }

    for(int i = 0; i < m; i++){
        string website;
        cin >> website;

        cout << passwords[website] << "\n";
    }

    return 0;
}