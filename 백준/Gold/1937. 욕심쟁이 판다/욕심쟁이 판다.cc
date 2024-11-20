#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct info{
    int row, col, bamboo;

    bool operator>(const info& other) const{
        return this->bamboo > other.bamboo;
    }
};
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> forest(n, vector<int>(n));
    priority_queue<info, vector<info>, greater<info>> pq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> forest[i][j];
            pq.push({i, j, forest[i][j]});
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 1));

    int answer = 1;
    while(!pq.empty()){
        int r = pq.top().row;
        int c = pq.top().col;
        pq.pop();

        for(auto [dr, dc] : dir){
            int next_r = r + dr;
            int next_c = c + dc;
            if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) continue;
            if(forest[next_r][next_c] <= forest[r][c]) continue;
            if(dp[next_r][next_c] < dp[r][c] + 1){
                dp[next_r][next_c] = dp[r][c] + 1;
                answer = max(answer, dp[next_r][next_c]);
            }
        }
    }

    cout << answer;

    return 0;
}