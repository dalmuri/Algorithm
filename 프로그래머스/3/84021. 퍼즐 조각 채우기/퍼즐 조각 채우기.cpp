#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 상 우 하 좌

bool cmp(vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

vector<vector<int>> turn90(vector<vector<int>> coordinates){
    vector<vector<int>> result;
    
    int row_max = coordinates[0][0];
    int col_max = coordinates[0][1];
    for(int i = 1; i < coordinates.size(); i++){
        row_max = max(row_max, coordinates[i][0]);
        col_max = max(col_max, coordinates[i][1]);
    }
    
    for(vector<int> c : coordinates) result.push_back({col_max - c[1], c[0]});
    
    sort(result.begin(), result.end(), cmp);
    return result;
}

bool equals(vector<vector<int>>& a, vector<vector<int>>& b){
    if(a.size() != b.size()) return false;
    
    for(int i = 0; i < a.size(); i++){
        if(a[i][0] != b[i][0]) return false;
        if(a[i][1] != b[i][1]) return false;
    }
    
    return true;
}

void get_block(int row, int col, int e, int n, int& row_min, int& col_min, vector<vector<int>>& game_board, vector<vector<bool>>& visited, vector<vector<int>>& coordinates){
    if(row < 0 || row >= n) return;
    if(col < 0 || col >= n) return;
    if(game_board[row][col] != e) return;
    if(visited[row][col]) return;
    
    visited[row][col] = true;
    coordinates.push_back({row, col});
    
    row_min = min(row_min, row);
    col_min = min(col_min, col);
    
    for(vector<int> dir : direction) get_block(row + dir[0], col + dir[1], e, n, row_min, col_min, game_board, visited, coordinates);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size();
    vector<vector<vector<int>>> empty_spaces;
    vector<vector<bool>> visited_board(n, vector<bool>(n, false));
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(game_board[r][c] == 0 && !visited_board[r][c]){
                vector<vector<int>> coordinates;
                int row_min = r;
                int col_min = c;
                get_block(r, c, 0, n, row_min, col_min, game_board, visited_board, coordinates);
                
                for(vector<int>& coor : coordinates){
                    coor[0] -= row_min;
                    coor[1] -= col_min;
                }
                
                sort(coordinates.begin(), coordinates.end(), cmp);
                empty_spaces.push_back(coordinates);
            }
        }
    }
    
    int m = table.size();
    vector<vector<vector<int>>> blocks;
    vector<vector<bool>> visited_table(m, vector<bool>(m, false));
    for(int r = 0; r < m; r++){
        for(int c = 0; c < m; c++){
            if(table[r][c] == 1 && !visited_table[r][c]){
                vector<vector<int>> coordinates;
                int row_min = r;
                int col_min = c;
                get_block(r, c, 1, m, row_min, col_min, table, visited_table, coordinates);
                
                for(vector<int>& coor : coordinates){
                    coor[0] -= row_min;
                    coor[1] -= col_min;
                }
                
                sort(coordinates.begin(), coordinates.end(), cmp);
                blocks.push_back(coordinates);
            }
        }
    }
    
    int answer = 0;
    vector<bool> filled(empty_spaces.size(), false);
    vector<bool> used(blocks.size(), false);
    for(int i = 0; i < 4; i++){
        if(i > 0){
            for(int b = 0; b < blocks.size(); b++) blocks[b] = turn90(blocks[b]);
        }
        
        for(int s = 0; s < empty_spaces.size(); s++){
            if(filled[s]) continue;
            for(int b = 0; b < blocks.size(); b++){
                if(used[b]) continue;
                
                if(equals(empty_spaces[s], blocks[b])){
                    answer += blocks[b].size();
                    filled[s] = true;
                    used[b] = true;
                    break;
                }
            }
        }
    }
    return answer;
}