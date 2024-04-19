#include <string>
#include <vector>

using namespace std;

bool can_build(int x, int y, int kind, int n, vector<vector<int>>& frame){
    if(kind == 0){ // 기둥
        if(y == 0) return true; // 바닥 위
        if(frame[x][y - 1] % 2 == 1) return true; // 기둥 위
        if(frame[x][y] == 2) return true; // 보의 왼쪽 위
        if(x > 0 && frame[x - 1][y] >= 2) return true; // 보의 오른쪽 위
    }
    else{ // 보
        if(y > 0 && frame[x][y - 1] % 2 == 1) return true; // 보의 왼쪽이 기둥 위
        if(x + 1 <= n && y > 0 && frame[x + 1][y - 1] % 2 == 1) return true; // 보의 오른쪽이 기둥 위
        if(x > 0 && x + 1 <= n && frame[x - 1][y] >= 2 && frame[x + 1][y] >= 2) return true; // 양쪽 보
    }
    return false;
}

bool can_remove(int x, int y, int kind, int n, vector<vector<int>>& frame){
    bool result = true;
    if(kind == 0){ // 기둥
        frame[x][y] -= 1;
        if(result && y + 1 <= n && frame[x][y + 1] % 2 == 1){ // 위에 기둥이 있는 경우
            frame[x][y + 1] -= 1;
            result = can_build(x, y + 1, 0, n, frame);
            frame[x][y + 1] += 1;
        }
        if(result && y + 1 <= n && frame[x][y + 1] >= 2){ // 위에 보의 왼쪽이 있는 경우
            frame[x][y + 1] -= 2;
            result = can_build(x, y + 1, 1, n, frame);
            frame[x][y + 1] += 2;
        }
        if(result && y + 1 <= n && x > 0 && frame[x - 1][y + 1] >= 2){ // 위에 보의 오른쪽이 있는 경우
            frame[x - 1][y + 1] -= 2;
            result = can_build(x - 1, y + 1, 1, n, frame);
            frame[x - 1][y + 1] += 2;
        }
        frame[x][y] += 1;
    }
    else{ // 보
        frame[x][y] -= 2;
        if(result && x > 0 && frame[x - 1][y] >= 2){ // 왼쪽에 보가 있는 경우
            frame[x - 1][y] -= 2;
            result = can_build(x - 1, y, 1, n, frame);
            frame[x - 1][y] += 2;
        }
        if(result && x + 1 <= n && frame[x + 1][y] >= 2){ // 오른쪽에 보가 있는 경우
            frame[x + 1][y] -= 2;
            result = can_build(x + 1, y, 1, n, frame);
            frame[x + 1][y] += 2;
        }
        if(result && frame[x][y] == 1){ // 왼쪽 위에 기둥이 있는 경우
            frame[x][y] -= 1;
            result = can_build(x, y, 0, n, frame);
            frame[x][y] += 1;
        }
        if(result && x + 1 <= n && frame[x + 1][y] % 2 == 1){ // 오른쪽 위에 기둥이 있는 경우
            frame[x + 1][y] -= 1;
            result = can_build(x + 1, y, 0, n, frame);
            frame[x + 1][y] += 1;
        }
        frame[x][y] += 2;
    }
    
    return result;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> frame(n + 1, vector<int>(n + 1, 0)); // 기둥: 1, 보: 2, 보&기둥: 3
    for(vector<int> cmd : build_frame){
        if(cmd[3] == 0){ // 삭제
            if(can_remove(cmd[0], cmd[1], cmd[2], n, frame)){
                frame[cmd[0]][cmd[1]] -= cmd[2] + 1;
            }
        }
        else{ // 설치
            if(can_build(cmd[0], cmd[1], cmd[2], n, frame)){
                frame[cmd[0]][cmd[1]] += cmd[2] + 1;
            }
        }
    }
    
    vector<vector<int>> answer;
    for(int x = 0; x <= n; x++){
        for(int y = 0; y <= n; y++){
            if(frame[x][y] == 1) answer.push_back({x, y, 0});
            else if(frame[x][y] == 2) answer.push_back({x, y, 1});
            else if(frame[x][y] == 3){
                answer.push_back({x, y, 0});
                answer.push_back({x, y, 1});
            }
        }
    }
    return answer;
}