#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int calc_dist(int now_r, int now_c, int dest_r, int dest_c, vector<vector<int>>& board){
    vector<vector<int>> dist(4, vector<int>(4, INT_MAX));
    queue<vector<int>> q; // {i, j, d} = (i, j) 까지 가는 거리 d
    q.push({now_r, now_c, 0});
    while(!q.empty()){
        int r = q.front()[0];
        int c = q.front()[1];
        int d = q.front()[2];
        q.pop();
        
        if(dist[r][c] <= d) continue;
        dist[r][c] = d;
        if(r == dest_r && c == dest_c) break;
        
        for(vector<int> dir : direction){
            int next_r = r + dir[0];
            int next_c = c + dir[1];
            if(next_r < 0 || next_r >= 4 || next_c < 0 || next_c >= 4) continue;
            q.push({next_r, next_c, d + 1});
            
            while(0 <= next_r && next_r < 4 && 0 <= next_c && next_c < 4 && !board[next_r][next_c]){
                next_r += dir[0];
                next_c += dir[1];
            }
            
            if(next_r < 0 || next_r >= 4 || next_c < 0 || next_c >= 4){
                next_r -= dir[0];
                next_c -= dir[1];
            }
            
            if(next_r == r + dir[0] && next_c == c + dir[c]) continue;
            q.push({next_r, next_c, d + 1});
        }
    }
    
    return dist[dest_r][dest_c];
}

vector<int> search_other(int r, int c, int select, vector<vector<int>>& board){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(r == i && c == j) continue;
            if(board[i][j] == select) return {i, j};
        }
    }
    
    return {-1, -1};
}

int search(int r, int c, vector<vector<int>>& board){
    int result = INT_MAX;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(!board[i][j]) continue;
            
            int select = board[i][j];
            vector<int> other = search_other(i, j, select, board);
            
            int cnt = calc_dist(r, c, i, j, board) + 1 + calc_dist(i, j, other[0], other[1], board) + 1;
            board[i][j] = 0;
            board[other[0]][other[1]] = 0;
            
            cnt += search(other[0], other[1], board);
            
            board[i][j] = select;
            board[other[0]][other[1]] = select;
            
            result = min(result, cnt);
        }
    }
    
    if(result == INT_MAX) return 0;
    return result;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = search(r, c, board);
    return answer;
}