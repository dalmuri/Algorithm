#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// clockHands[row][col]과 그 상하좌우의 시계를 cnt 횟수만큼 조작
void turn(int row, int col, int n, int cnt, vector<vector<int>>& clockHands){
    clockHands[row][col] = (clockHands[row][col] + cnt) % 4;
    
    if(row > 0) clockHands[row - 1][col] = (clockHands[row - 1][col] + cnt) % 4;
    if(row + 1 < n) clockHands[row + 1][col] = (clockHands[row + 1][col] + cnt) % 4;
    if(col > 0) clockHands[row][col - 1] = (clockHands[row][col - 1] + cnt) % 4;
    if(col + 1 < n) clockHands[row][col + 1] = (clockHands[row][col + 1] + cnt) % 4;
}

// 첫 번째 행에 맞춰 다른 모든 행을 조작하여 그 횟수를 반환
// 모든 시계가 12시를 바라보지 않는다면 -1을 반환
int control(int n, vector<vector<int>>& clockHands){
    int result = 0;
    for(int r = 1; r < n; r++){
        for(int c = 0; c < n; c++){
            if(clockHands[r - 1][c] > 0){
                result += 4 - clockHands[r - 1][c];
                turn(r, c, n, 4 - clockHands[r - 1][c], clockHands);
            }
        }
    }
    
    // 마지막 줄을 확인해서 퍼즐이 해결됐는지 체크
    for(int c = 0; c < n; c++){
        if(clockHands[n - 1][c] > 0) return -1;
    }
    
    return result;
}

// 첫 번째 행 조작하여 조작 횟수를 반환
int set_row0(int num, int n, vector<vector<int>>& clockHands){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int t = num % 4;
        num = num / 4;
        
        if(t > 0){
            turn(0, i, n, t, clockHands);
            cnt += t;
        }
        
        if(num == 0) break;
    }
    
    return cnt;
}

int solution(vector<vector<int>> clockHands) {
    int n = clockHands.size();
    int answer = INT_MAX;
    
    for(int i = 0; i < pow(4, n); i++){
        vector<vector<int>> cpy(clockHands);
        int cnt1 = set_row0(i, n, cpy); // 첫 번째 행 조작
        
        int cnt2 = control(n, cpy); // 다른 모든 행 조작
        if(cnt2 != -1) answer = min(answer, cnt1 + cnt2); // 조작 성공
    }
    
    return answer;
}