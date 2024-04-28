#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 상 우 하 좌
int n = 102;
int inf = 2000;
vector<vector<int>> plane(n, vector<int>(n, 0)); // 0: 빈 공간, 1: 선 위, 2: 다각형 내부
vector<vector<int>> dist(n, vector<int>(n, inf));
queue<vector<int>> q;

void search(){
    int x = q.front()[0];
    int y = q.front()[1];
    int len = q.front()[2];
    q.pop();
    
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    if(plane[x][y] != 1) return;
    if(dist[x][y] <= len) return;
    
    dist[x][y] = len;
    
    for(vector<int> dir : direction){
        q.push({x + dir[0], y + dir[1], len + 1});
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(vector<int> rec : rectangle){
        for(int x = rec[0] * 2; x <= rec[2] * 2; x++){
            for(int y = rec[1] * 2; y <= rec[3] * 2; y++){
                if(plane[x][y] == 2) continue;
                
                if(x == rec[0] * 2 || x == rec[2] * 2 || y == rec[1] * 2 || y == rec[3] * 2)
                    plane[x][y] = 1;
                else
                    plane[x][y] = 2;
            }
        }
    }
    
    int dest_x = itemX * 2;
    int dest_y = itemY * 2;
    q.push({characterX * 2, characterY * 2, 0});
    while(!q.empty()){
        search();
        
        if(dist[dest_x][dest_y] < inf) break;
    }
    
    return dist[dest_x][dest_y] / 2;
}