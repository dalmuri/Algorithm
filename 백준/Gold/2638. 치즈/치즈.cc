#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void update_air(int row, int col, vector<vector<int>>& cheese){
    for(vector<int> d : dir){
        int next_row = row + d[0];
        int next_col = col + d[1];
        if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
        if(cheese[next_row][next_col] == 0){
            cheese[next_row][next_col] = -1;
            update_air(next_row, next_col, cheese);
        }
    }
}

void melt(int& count, vector<vector<int>>& cheese){
    vector<vector<int>> next_cheese(cheese);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cheese[i][j] != 1) continue;

            int air_adj = 0;
            for(vector<int> d : dir){
                int next_i = i + d[0];
                int next_j = j + d[1];
                if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) continue;
                if(cheese[next_i][next_j] == -1) air_adj++;
            }

            if(air_adj >= 2){
                next_cheese[i][j] = -1;
                count--;
                update_air(i, j, next_cheese);
            }
        }
    }

    cheese = next_cheese;
}

int main(){
    FASTIO

    cin >> n >> m;
    vector<vector<int>> cheese(n, vector<int>(m)); // 1: 치즈, 0: 내부공기, -1: 외부공기
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cheese[i][j];
            count += cheese[i][j];
        }
    }

    cheese[0][0] = -1;
    update_air(0, 0, cheese);

    int answer = 0;
    while(count > 0){
        answer++;
        melt(count, cheese);
    }

    cout << answer;

    return 0;
}