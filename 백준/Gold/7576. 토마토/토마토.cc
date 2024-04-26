#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int inf = 1000001;

int main(){
    int n, m;
    cin >> m >> n;
    vector<vector<int>> tomato(n, vector<int>(m, 0));
    vector<vector<int>> days(n, vector<int>(m, inf));
    queue<vector<int>> q;
    for(int r = 0; r < n; r++){
        for(int c = 0; c< m; c++){
            cin >> tomato[r][c];
            if(tomato[r][c] == 1) q.push({r, c, 0});
        }
    }
    
    while(!q.empty()){
        int row = q.front()[0];
        int col = q.front()[1];
        int day = q.front()[2];
        q.pop();
        if(days[row][col] <= day) continue;
        
        days[row][col] = day;
        
        for(vector<int> dir : direction){
            int next_row = row + dir[0];
            int next_col = col + dir[1];
            if(next_row < 0 || next_row >= n) continue;
            if(next_col < 0 || next_col >= m) continue;
            if(tomato[next_row][next_col] != 0) continue;
            
            q.push({next_row, next_col, day + 1});
        }
    }
    
    int answer = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(tomato[r][c] != -1) answer = max(answer, days[r][c]);
        }
    }
    
    if(answer == inf) answer = -1;
    cout << answer << endl;
    
    return 0;
}