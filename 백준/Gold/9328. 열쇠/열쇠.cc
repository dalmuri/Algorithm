#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    FASTIO

    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;

        vector<string> building(h);
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        vector<bool> has_key(26, false);
        vector<queue<pair<int, int>>> doors(26);
        queue<pair<int, int>> q;
        for (int i = 0; i < h; i++){
            cin >> building[i];
        }

        string kk;
        cin >> kk;
        if (kk != "0"){
            for(char k : kk) has_key[k - 'a'] = true;
        }

        for(int i = 0; i < h; i++){
            if(i == 0 || i == h - 1){
                for(int j = 0; j < w; j++){
                    if(building[i][j] == '*') continue;

                    if('A' <= building[i][j] && building[i][j] <= 'Z' && !has_key[building[i][j] - 'A']) doors[building[i][j] - 'A'].push({i, j});
                    else q.push({i, j});
                }
            }
            else{
                if(building[i][0] != '*'){
                    if ('A' <= building[i][0] && building[i][0] <= 'Z' && !has_key[building[i][0] - 'A']) doors[building[i][0] - 'A'].push({i, 0});
                    else q.push({i, 0});
                }

                if(building[i][w - 1] != '*'){
                    if ('A' <= building[i][w - 1] && building[i][w - 1] <= 'Z' && !has_key[building[i][w - 1] - 'A']) doors[building[i][w - 1] - 'A'].push({i, w - 1});
                    else q.push({i, w - 1});
                }
            }
        }

        int answer = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(visited[r][c]) continue;
            visited[r][c] = true;

            if(building[r][c] == '$') answer++;
            else if('a' <= building[r][c] && building[r][c] <= 'z'){
                int idx = building[r][c] - 'a';
                has_key[idx] = true;
                while(!doors[idx].empty()){
                    q.push({doors[idx].front().first, doors[idx].front().second});
                    doors[idx].pop();
                }
            }
            else if('A' <= building[r][c] && building[r][c] <= 'Z' && !has_key[building[r][c] - 'A']){
                doors[building[r][c] - 'A'].push({r, c});
                continue;
            }

            for(vector<int> d : dir){
                int next_r = r + d[0];
                int next_c = c + d[1];
                if(next_r < 0 || next_r >= h || next_c < 0 || next_c >= w) continue;
                if(building[next_r][next_c] == '*') continue;
                if(visited[next_r][next_c]) continue;

                if('A' <= building[next_r][next_c] && building[next_r][next_c] <= 'Z'){
                    if(has_key[building[next_r][next_c] - 'A']) q.push({next_r, next_c});
                    else doors[building[next_r][next_c] - 'A'].push({next_r, next_c});
                }
                else q.push({next_r, next_c});
            }
        }

        cout << answer << "\n";
    }

    return 0;
}