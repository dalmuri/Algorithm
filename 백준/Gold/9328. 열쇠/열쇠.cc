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
        list<pair<int, int>> doors;
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
                    if(building[i][j] != '*'){
                        if('A' <= building[i][j] && building[i][j] <= 'Z' && !has_key[building[i][j] - 'A']) doors.push_back({i, j});
                        else q.push({i, j});
                    }
                }
            }
            else{
                if(building[i][0] != '*'){
                    if ('A' <= building[i][0] && building[i][0] <= 'Z' && !has_key[building[i][0] - 'A']) doors.push_back({i, 0});
                    else q.push({i, 0});
                }

                if(building[i][w - 1] != '*'){
                    if ('A' <= building[i][w - 1] && building[i][w - 1] <= 'Z' && !has_key[building[i][w - 1] - 'A']) doors.push_back({i, w - 1});
                    else q.push({i, w - 1});
                }
            }
        }

        int answer = 0;
        while(!q.empty()){
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if(visited[r][c]) continue;
                visited[r][c] = true;

                if('A' <= building[r][c] && building[r][c] <= 'Z' && !has_key[building[r][c] - 'A']) continue;
                
                if(building[r][c] == '$') answer++;
                else if('a' <= building[r][c] && building[r][c] <= 'z') has_key[building[r][c] - 'a'] = true;

                for(vector<int> d : dir){
                    int next_r = r + d[0];
                    int next_c = c + d[1];
                    if(next_r < 0 || next_r >= h || next_c < 0 || next_c >= w) continue;
                    if(building[next_r][next_c] == '*') continue;
                    if(visited[next_r][next_c]) continue;

                    if('A' <= building[next_r][next_c] && building[next_r][next_c] <= 'Z'){
                        if (has_key[building[next_r][next_c] - 'A']) q.push({next_r, next_c});
                        else doors.push_back({next_r, next_c});
                    }
                    else q.push({next_r, next_c});
                }
            }

            for(auto iter = doors.begin(); iter != doors.end(); iter++){
                int r = (*iter).first;
                int c = (*iter).second;

                if(has_key[building[r][c] - 'A']){
                    q.push({r, c});
                    auto to_del = iter--;
                    doors.erase(to_del);
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}