#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int to(char color){
    if(color == 'B') return 0;
    else return 1;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    string colors;
    cin >> colors;

    vector<int> counts(2, 0);
    ++counts[to(colors[0])];

    for(int i = 1; i < n; ++i){
        if(colors[i] == colors[i - 1]) continue;

        ++counts[to(colors[i])];
    }

    cout << min(counts[0], counts[1]) + 1;

    return 0;
}