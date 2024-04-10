#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int search(int row, int col, int n, int m, vector<vector<bool>>& visited, vector<string>& maps){
    if(row < 0 || row >= n || col < 0 || col >= m) return 0;
    if(visited[row][col]) return 0;
    if(maps[row][col] == 'X') return 0;
    
    visited[row][col] = true;
    int result = maps[row][col] - '0';
    for(vector<int> d : direction){
        result += search(row + d[0], col + d[1], n, m, visited, maps);
    }
    return result;
}

vector<int> solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    vector<int> answer;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            int days = search(r, c, n, m, visited, maps);
            if(days > 0) answer.push_back(days);
        }
    }
    
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}