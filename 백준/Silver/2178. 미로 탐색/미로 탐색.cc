#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int inf = 1234567;
vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m;
vector<vector<char>> maze;
vector<vector<int>> dist;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[2] > b[2];
    }
};

void search(){
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({0, 0, 1});

    while(!pq.empty()){
        int r = pq.top()[0];
        int c = pq.top()[1];
        int d = pq.top()[2];
        pq.pop();

        if(r == n - 1 && c == m - 1) return;
        if(dist[r][c] < d) continue;

        for(vector<int> dir : direction){
            int next_r = r + dir[0];
            int next_c = c + dir[1];
            if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) continue;
            if(maze[next_r][next_c] == '0') continue;
            if(dist[next_r][next_c] <= d + 1) continue;

            dist[next_r][next_c] = d + 1;
            pq.push({next_r, next_c, d + 1});
        }
    }
}

int main(){
    FASTIO

    cin >> n >> m;
    maze = vector<vector<char>>(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    dist = vector<vector<int>>(n, vector<int>(m, inf));
    dist[0][0] = 1;

    search();

    cout << dist[n - 1][m - 1];

    return 0;
}