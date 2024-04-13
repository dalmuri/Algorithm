#include <string>
#include <vector>

using namespace std;

vector<vector<int>> reverse_dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool move(int dist, int& start, int& end, int range){
    start += (start == 0 && dist > 0) ? 0 : dist;
    end += (end == range - 1 && dist < 0) ? 0 : dist;
    
    if(start >= range || end < 0) return false;
    
    if(start < 0) start = 0;
    if(end >= range) end = range - 1;
    
    return true;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    int row_start = x, row_end = x;
    int col_start = y, col_end = y;
    
    for(int i = queries.size() - 1; i >= 0; i--){
        if(queries[i][0] > 1){ // move row
            if(!move(reverse_dir[queries[i][0]][0] * queries[i][1], row_start, row_end, n)) return 0;
        }
        else{ // move column
            if(!move(reverse_dir[queries[i][0]][1] * queries[i][1], col_start, col_end, m)) return 0;
        }
    }
    return (long long)(row_end - row_start + 1) * (col_end - col_start + 1);
}