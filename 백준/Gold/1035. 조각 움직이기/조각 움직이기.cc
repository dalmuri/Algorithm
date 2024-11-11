#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dist(pair<int, int> piece, int r, int c){
    return abs(r - piece.first) + abs(c - piece.second);
}

bool is_adjacent(int n, vector<vector<bool>>& visited){
    vector<vector<bool>> checked(5, vector<bool>(5, false));
    queue<pair<int, int>> q;
    int adj = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(visited[i][j]){
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
        if(adj == n) return true;

        for(vector<int> d : dir){
            int dr = r + d[0];
            int dc = c + d[1];
            if(dr < 0 || dr >= 5 || dc < 0 || dc >= 5) continue;
            if(!visited[dr][dc]) continue;
            if(checked[dr][dc]) continue;

            q.push({dr, dc});
            checked[dr][dc] = true;
        }
    }

    return false;
}

void search(int idx, int cnt, int& answer, vector<pair<int, int>>& pieces, vector<vector<bool>>& visited){
    if(idx == pieces.size()){
        if(is_adjacent(pieces.size(), visited)) answer = min(answer, cnt);
        return;
    }
    if(cnt >= answer) return;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(visited[i][j]) continue;

            visited[i][j] = true;
            search(idx + 1, cnt + dist(pieces[idx], i, j), answer, pieces, visited);
            visited[i][j] = false;
        }
    }
}

int main(){
    FASTIO

    vector<vector<char>> board(5, vector<char>(5));
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    vector<pair<int, int>> pieces;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> board[i][j];

            if(board[i][j] == '*') pieces.push_back({i, j});
        }
    }

    int answer = 100;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            visited[i][j] = true;
            search(1, dist(pieces[0], i, j), answer, pieces, visited);
            visited[i][j] = false;
        }
    }

    cout << answer;

    return 0;
}