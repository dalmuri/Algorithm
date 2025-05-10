#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    unordered_map<int, int> arrows;
    int answer = 0;
    for(int i = 0; i < n; ++i){
        int balloon;
        cin >> balloon;

        auto iter = arrows.find(balloon);
        if(iter != arrows.end() && iter->second > 0) --iter->second;
        else ++answer;

        if(balloon > 1) ++arrows[balloon - 1];
    }

    cout << answer;

    return 0;
}