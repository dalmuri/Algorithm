#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int put(int row_now, int col_now, int dir, int row_min, int col_min, int row_max, int col_max, vector<vector<int>> &matrix){
    int row_next = row_now + direction[dir][0];
    int col_next = col_now + direction[dir][1];
    
    if(row_next < row_min || row_next > row_max || col_next < col_min || col_next > col_max){
        dir++;
        if(dir >= direction.size()) return INT_MAX;
        row_next = row_now + direction[dir][0];
        col_next = col_now + direction[dir][1];
    }
    
    int value = matrix[row_next][col_next];
    matrix[row_now][col_now] = value;
    return min(value, put(row_next, col_next, dir, row_min, col_min, row_max, col_max, matrix));
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = i * columns + j + 1;
        }
    }
    
    for(vector<int> query : queries){
        for(int i = 0; i < query.size(); i++) query[i] = query[i] - 1;
        
        int tmp = matrix[query[0]][query[1]];
        int m = put(query[0], query[1], 0, query[0], query[1], query[2], query[3], matrix);
        matrix[query[0]][query[1]+1] = tmp;
        answer.push_back(min(tmp, m));
    }
    
    return answer;
}