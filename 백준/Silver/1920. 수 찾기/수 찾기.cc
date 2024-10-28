#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n;

    unordered_set<int> exists;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        exists.insert(num);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        if(exists.find(num) != exists.end()) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}