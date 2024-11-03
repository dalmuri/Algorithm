#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int inf = 123456789;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, inf)));
    dist[0][0][0] = 1;
    queue<tuple<int, int, int>> q; // r, c, broken
    q.push({0, 0, 0});
    while(!q.empty()){
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int broken = get<2>(q.front());
        q.pop();

        if(r == n - 1 && c == m - 1) break;

        for(vector<int> d : dir){
            int next_r = r + d[0];
            int next_c = c + d[1];
            if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) continue;
            
            if(board[next_r][next_c] == '1'){
                if(broken == 0 && dist[r][c][0] + 1 < dist[next_r][next_c][1]){
                    dist[next_r][next_c][1] = dist[r][c][0] + 1;
                    q.push({next_r, next_c, 1});
                }
                continue;
            }
            
            if(dist[r][c][broken] + 1 < dist[next_r][next_c][broken]){
                dist[next_r][next_c][broken] = dist[r][c][broken] + 1;
                q.push({next_r, next_c, broken});
            }
        }
    }

    int answer = min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    cout << (answer < inf ? answer : -1);

    return 0;
}