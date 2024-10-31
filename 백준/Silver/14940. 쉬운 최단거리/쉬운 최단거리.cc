#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int inf = 12345678;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int n, m;
    cin >> n >> m;

    int dest_r, dest_c;
    vector<vector<int>> ground(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ground[i][j];

            if(ground[i][j] == 2){
                dest_r = i;
                dest_c = j;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, inf));
    dist[dest_r][dest_c] = 0;
    queue<pair<int, int>> q;
    q.push({dest_r, dest_c});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(vector<int> d : dir){
            int next_r = r + d[0];
            int next_c = c + d[1];
            if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) continue;
            if(ground[next_r][next_c] == 0) continue;
            if(dist[next_r][next_c] <= dist[r][c] + 1) continue;

            dist[next_r][next_c] = dist[r][c] + 1;
            q.push({next_r, next_c});
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ground[i][j] == 0) cout << "0 ";
            else if(dist[i][j] == inf) cout << "-1 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}