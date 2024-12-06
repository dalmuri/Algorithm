#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 987654321;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m;

bool is_in(int row, int col){
    if(row < 0 || row >= n || col < 0 || col >= m) return false;
    return true;
}

void make_island(int row, int col, int num, vector<vector<int>>& board){
    board[row][col] = num;

    for(int* d : dir){
        int dr = row + d[0];
        int dc = col + d[1];
        if(!is_in(dr, dc)) continue;
        if(board[dr][dc] != 1) continue;

        make_island(dr, dc, num, board);
    }
}

void make_bridge(int row, int col, vector<vector<int>>& dist, vector<vector<int>>& board){
    for(int* d : dir){
        int dr = row;
        int dc = col;
        int cnt = -1;
        while(is_in(dr + d[0], dc + d[1])){
            dr += d[0];
            dc += d[1];
            cnt++;
            if(board[dr][dc] != 0) break;
        }
        if(board[dr][dc] == 0 || board[dr][dc] == board[row][col]) continue;
        if(cnt < 2) continue;

        dist[board[row][col]][board[dr][dc]] = min(dist[board[row][col]][board[dr][dc]], cnt);
        dist[board[dr][dc]][board[row][col]] = min(dist[board[dr][dc]][board[row][col]], cnt);
    }
}

int get_root(int num, vector<int>& root){
    if(root[num] == -1) return num;
    return root[num] = get_root(root[num], root);
}

bool union_root(int a, int b, vector<int>& root){
    int root_a = get_root(a, root);
    int root_b = get_root(b, root);

    if(root_a == root_b) return false;

    root[max(root_a, root_b)] = min(root_a, root_b);
    return true;
}

int main(){
    FASTIO

    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int island = 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1) make_island(i, j, island++, board);
        }
    }

    vector<vector<int>> dist(island, vector<int>(island, inf));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] > 0) make_bridge(i, j, dist, board);
        }
    }

    using tpi = tuple<int, int, int>;
    priority_queue<tpi, vector<tpi>, greater<tpi>> pq;
    for(int i = 2; i + 1 < island; i++){
        for(int j = i + 1; j < island; j++){
            if(dist[i][j] < inf) pq.push({dist[i][j], i, j});
        }
    }

    vector<int> root(island, -1);
    int answer = 0;
    int connected_cnt = 0;
    while(!pq.empty()){
        auto [distance, a, b] = pq.top();
        pq.pop();

        if(union_root(a, b, root)) answer += distance, connected_cnt++;
    }

    cout << (connected_cnt == island - 3 ? answer : -1);

    return 0;
}