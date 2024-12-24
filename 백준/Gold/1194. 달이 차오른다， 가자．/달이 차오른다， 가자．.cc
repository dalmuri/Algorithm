#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 987654321;
const int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct state{
    int row, col, key;
};

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(1 << 6, inf)));
    pair<int, int> start;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];

            if(maze[i][j] == '0') start = {i, j};
        }
    }

    dist[start.first][start.second][0] = 0;
    queue<state> q;
    q.push({start.first, start.second, 0});

    int answer = inf;
    while(!q.empty()){
        auto [r, c, key] = q.front();
        int d = dist[r][c][key];
        q.pop();

        if(maze[r][c] == '1'){
            answer = dist[r][c][key];
            break;
        }
        else if('a' <= maze[r][c] && maze[r][c] <= 'f'){
            if(!(key & (1 << (maze[r][c] - 'a')))){ // new key
                key |= 1 << (maze[r][c] - 'a');
                dist[r][c][key] = d;
            }
        }
        else if('A' <= maze[r][c] && maze[r][c] <= 'F'){
            if(!(key & (1 << (maze[r][c] - 'A')))) continue;
        }

        for(auto [dr, dc] : direction){
            int next_r = r + dr;
            int next_c = c + dc;
            if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) continue;
            if(maze[next_r][next_c] == '#') continue;
            if(dist[next_r][next_c][key] <= d + 1) continue;

            dist[next_r][next_c][key] = d + 1;
            q.push({next_r, next_c, key});
        }
    }

    cout << (answer < inf ? answer : -1);

    return 0;
}