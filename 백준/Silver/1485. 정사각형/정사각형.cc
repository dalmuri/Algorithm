#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int dist(pair<int, int>& p1, pair<int, int>& p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main(){
    FASTIO

    vector<pair<int, int>> square(4);

    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 4; ++i) cin >> square[i].first >> square[i].second;

        vector<int> lines;
        for(int i = 0; i + 1 < square.size(); ++i){
            for(int j = i + 1; j < square.size(); ++j){
                lines.push_back(dist(square[i], square[j]));
            }
        }

        sort(lines.begin(), lines.end());

        if(lines[0] == lines[1] && lines[0] == lines[2] && lines[0] == lines[3] && lines[4] == lines[5]) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}