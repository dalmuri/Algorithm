#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    const int inf = 1'000'000'001;

    int n;
    cin >> n;

    vector<vector<int>> points(n + 1);
    for(int i = 0, x, color; i < n; ++i){
        cin >> x >> color;
        points[color].push_back(x);
    }

    for(int i = 1; i <= n; ++i) sort(points[i].begin(), points[i].end());

    long long answer = 0ll;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < points[i].size(); ++j){
            int len = inf;
            if(j > 0) len = min(len, points[i][j] - points[i][j - 1]);
            if(j + 1 < points[i].size()) len = min(len, points[i][j + 1] - points[i][j]);

            answer += len < inf ? len : 0;
        }
    }

    cout << answer;

    return 0;
}