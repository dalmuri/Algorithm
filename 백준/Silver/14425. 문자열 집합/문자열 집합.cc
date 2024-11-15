#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    set<string> s;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    int answer = 0;
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        if(s.find(str) != s.end()) answer++;
    }

    cout << answer;

    return 0;
}