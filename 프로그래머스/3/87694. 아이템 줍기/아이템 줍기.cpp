#include <vector>

using namespace std;

vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 상 우 하 좌
int n = 102;
int inf = 2000;
int dest_x, dest_y;
vector<vector<int>> plane(n, vector<int>(n, 0)); // 0: 빈 공간, 1: 선 위, 2: 다각형 내부
vector<vector<int>> dist(n, vector<int>(n, inf));

void search(int x, int y, int len){
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    if(plane[x][y] != 1) return;
    if(dist[x][y] <= len) return;
    
    dist[x][y] = len;
    if(x == dest_x && y == dest_y) return;
    
    for(vector<int> dir : direction){
        search(x + dir[0], y + dir[1], len + 1);
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
    
    dest_x = itemX * 2;
    dest_y = itemY * 2;
    search(characterX * 2, characterY * 2, 0);
    
    return dist[dest_x][dest_y] / 2;
}