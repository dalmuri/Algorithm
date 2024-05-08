#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> direction = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}; // 8방향
int n, m;

bool BFS(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& farm){
    queue<vector<int>> q; // {r, c}
    q.push({r, c});
    int height = farm[r][c];
    bool result = true;
    while(!q.empty()){
        int now_r = q.front()[0];
        int now_c = q.front()[1];
        q.pop();
        visited[now_r][now_c] = true;

        for(vector<int> dir : direction){
            int next_r = now_r + dir[0];
            int next_c = now_c + dir[1];
            if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) continue;
            if(farm[next_r][next_c] > height) result = false;
            if(farm[next_r][next_c] != height) continue;
            if(visited[next_r][next_c]) continue;

            q.push({next_r, next_c});
        }
    }

    return result;
}

int main() {
    cin >> n >> m;

    vector<vector<int>> farm(n, vector<int>(m, 0));
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> farm[r][c];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int answer = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(visited[r][c]) continue;

            if(BFS(r, c, visited, farm)) answer++;
        }
    }

    cout << answer << endl;
    
    return 0;
}