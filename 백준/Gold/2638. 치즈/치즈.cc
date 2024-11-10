#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> cheese;
vector<vector<int>> adj_cnt;

void update_air(int row, int col, queue<pair<int, int>>& q){
    for(vector<int> d : dir){
        int next_row = row + d[0];
        int next_col = col + d[1];
        if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
        if(cheese[next_row][next_col] == 0){
            cheese[next_row][next_col] = -1;
            update_air(next_row, next_col, q);
        }
        else if(cheese[next_row][next_col] == 1){
            adj_cnt[next_row][next_col]++;
            if(adj_cnt[next_row][next_col] == 2) q.push({next_row, next_col});
        }
    }
}

int main(){
    FASTIO

    cin >> n >> m;
    cheese = vector<vector<int>>(n, vector<int>(m)); // 1: 치즈, 0: 내부공기, -1: 외부공기
    adj_cnt = vector<vector<int>>(n, vector<int>(m, 0));
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cheese[i][j];
            count += cheese[i][j];
        }
    }

    queue<pair<int, int>> q;
    cheese[0][0] = -1;
    update_air(0, 0, q);

    int answer = 0;
    while(count > 0){
        answer++;

        queue<pair<int, int>> to_melt_q;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            cheese[row][col] = -1;
            count--;

            update_air(row, col, to_melt_q);
        }
        
        q = to_melt_q;
    }

    cout << answer;

    return 0;
}