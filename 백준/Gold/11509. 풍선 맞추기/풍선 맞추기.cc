#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> balloons(n);
    for(int i = 0; i < n; ++i) cin >> balloons[i];

    unordered_map<int, int> arrows;
    int answer = 0;
    for(int i = 0; i < n; ++i){
        auto iter = arrows.find(balloons[i]);
        if(iter != arrows.end() && iter->second > 0) --iter->second;
        else ++answer;

        if(balloons[i] > 1) ++arrows[balloons[i] - 1];
    }

    cout << answer;

    return 0;
}