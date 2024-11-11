#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<pair<int, int>> pieces;
bool used[5][5] = {false};

int dist(pair<int, int> piece, int r, int c){
    return abs(r - piece.first) + abs(c - piece.second);
}

bool is_adjacent(){
    bool checked[5][5] = {false};
    queue<pair<int, int>> q;
    int adj = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(used[i][j]){
                q.push({i, j});
                checked[i][j] = true;
                break;
            }
        }
        if(!q.empty()) break;
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        adj++;
        if(adj == pieces.size()) return true;

        for(int* d : dir){
            int dr = r + d[0];
            int dc = c + d[1];
            if(dr < 0 || dr >= 5 || dc < 0 || dc >= 5) continue;
            if(!used[dr][dc]) continue;
            if(checked[dr][dc]) continue;

            q.push({dr, dc});
            checked[dr][dc] = true;
        }
    }

    return false;
}

void search(int idx, int cnt, int& answer){
    if(idx == pieces.size()){
        if(is_adjacent()) answer = min(answer, cnt);
        return;
    }
    if(cnt >= answer) return;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(used[i][j]) continue;

            used[i][j] = true;
            search(idx + 1, cnt + dist(pieces[idx], i, j), answer);
            used[i][j] = false;
        }
    }
}

int main(){
    FASTIO

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            char c;
            cin >> c;

            if(c == '*') pieces.push_back({i, j});
        }
    }

    int answer = 100;
    search(0, 0, answer);

    cout << answer;

    return 0;
}