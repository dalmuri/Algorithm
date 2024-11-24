#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<pair<int, int>> cctvs;
vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int monitor(int r, int c, int dir, vector<vector<int>>& room){
    r += direction[dir][0];
    c += direction[dir][1];
    int result = 0;
    while(0 <= r && r < n && 0 <= c && c < m && room[r][c] != 6){
        if(room[r][c] == 0){
            room[r][c] = 9;
            result++;
        }
        
        r += direction[dir][0];
        c += direction[dir][1];
    }

    return result;
}

int count_monitoring_area(int idx, vector<vector<int>>& room){
    if(idx == cctvs.size()) return 0;

    int r = cctvs[idx].first;
    int c = cctvs[idx].second;
    int type = room[r][c];

    int result = 0;
    if(type == 1){
        for(int dir = 0; dir < 4; dir++){
            vector<vector<int>> next_room(room);
            int cnt = monitor(r, c, dir, next_room);
            
            cnt += count_monitoring_area(idx + 1, next_room);
            
            result = max(result, cnt);
        }
    }
    else if(type == 2){
        for(int dir = 0; dir < 2; dir++){
            vector<vector<int>> next_room(room);
            int cnt = monitor(r, c, dir, next_room);
            cnt += monitor(r, c, dir + 2, next_room);

            cnt += count_monitoring_area(idx + 1, next_room);

            result = max(result, cnt);
        }
    }
    else if(type == 3){
        for(int dir = 0; dir < 4; dir++){
            vector<vector<int>> next_room(room);
            int cnt = monitor(r, c, dir, next_room);
            cnt += monitor(r, c, (dir + 1) % 4, next_room);

            cnt += count_monitoring_area(idx + 1, next_room);

            result = max(result, cnt);
        }
    }
    else if(type == 4){
        for(int dir = 0; dir < 4; dir++){
            vector<vector<int>> next_room(room);
            int cnt = monitor(r, c, dir, next_room);
            cnt += monitor(r, c, (dir + 1) % 4, next_room);
            cnt += monitor(r, c, (dir + 2) % 4, next_room);

            cnt += count_monitoring_area(idx + 1, next_room);

            result = max(result, cnt);
        }
    }
    else{
        result = count_monitoring_area(idx + 1, room);
    }

    return result;
}

int main(){
    FASTIO

    cin >> n >> m;

    int max_area = 0;

    vector<vector<int>> room(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];

            if(1 <= room[i][j] && room[i][j] <= 5) cctvs.push_back({i, j});
            else if(room[i][j] == 0) max_area++;
        }
    }

    for(auto [r, c] : cctvs){
        if(room[r][c] != 5) continue;

        for(int dir = 0; dir < 4; dir++){
            max_area -= monitor(r, c, dir, room);
        }
    }

    cout << max_area - count_monitoring_area(0, room);

    return 0;
}