#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int g, p;
    cin >> g >> p;
    set<int> s;
    for(int i = 1; i <= g; i++) s.insert(i);

    int answer = 0;
    for(int i = 0; i < p; i++){
        int plane;
        cin >> plane;

        auto iter = s.upper_bound(plane);
        if(iter == s.begin()) break;

        s.erase(--iter);
        answer++;
    }

    cout << answer;

    return 0;
}