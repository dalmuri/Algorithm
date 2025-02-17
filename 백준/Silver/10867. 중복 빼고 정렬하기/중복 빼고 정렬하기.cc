#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    set<int> s;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        s.insert(num);
    }

    for(auto iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << " ";
    }

    return 0;
}