#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool can_erase(int r1, int c1, int r2, int c2, vector<string>& board){
    if(r1 == r2){
        for(int c = min(c1, c2) + 1; c < max(c1, c2); c++){
            if(board[r1][c] != '.') return false;
        }
        return true;
    }
    else if(c1 == c2){
        for(int r = min(r1, r2) + 1; r < max(r1, r2); r++){
            if(board[r][c1] != '.') return false;
        }
        return true;
    }
    else{
        // path1
        bool chk1 = board[r2][c1] == '.';
        
        for(int r = min(r1, r2) + 1; r < max(r1, r2) && chk1; r++){
            if(board[r][c1] != '.'){
                chk1 = false;
                break;
            }
        }
        for(int c = min(c1, c2) + 1; c < max(c1, c2) && chk1; c++){
            if(board[r2][c] != '.'){
                chk1 = false;
                break;
            }
        }
        if(chk1) return true;
        
        // path2
        bool chk2 = board[r1][c2] == '.';
        
        for(int r = min(r1, r2) + 1; r < max(r1, r2) && chk2; r++){
            if(board[r][c2] != '.'){
                chk2 = false;
                break;
            }
        }
        for(int c = min(c1, c2) + 1; c < max(c1, c2) && chk2; c++){
            if(board[r1][c] != '.'){
                chk2 = false;
                break;
            }
        }
        if(chk2) return true;
        
        return false;
    }
}

string solution(int m, int n, vector<string> board) {
    vector<vector<int>> pos(26, vector<int>());
    vector<bool> is_in(26, false);
    int cnt = 0;
    priority_queue<int> pq;
    string answer = "";
    
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            if(board[r][c] == '.' || board[r][c] == '*') continue;
            
            is_in[board[r][c] - 'A'] = true;
            pos[board[r][c] - 'A'].push_back(r);
            pos[board[r][c] - 'A'].push_back(c);
            cnt++;
            
            if(pos[board[r][c] - 'A'].size() == 4 && can_erase(pos[board[r][c] - 'A'][0], pos[board[r][c] - 'A'][1], pos[board[r][c] - 'A'][2], pos[board[r][c] - 'A'][3], board)){
                pq.push(-(board[r][c] - 'A'));
                is_in[board[r][c] - 'A'] = false;
            }
        }
    }
    
    while(!pq.empty()){

        int ch = -pq.top();
        board[pos[ch][0]][pos[ch][1]] = '.';
        board[pos[ch][2]][pos[ch][3]] = '.';
        answer += (ch + 'A');
        pq.pop();
            
        cnt -= 2;

        
        if(cnt == 0) break;
        
        for(int i = 0; i < is_in.size(); i++){
            if(!is_in[i]) continue;
            if(can_erase(pos[i][0], pos[i][1], pos[i][2], pos[i][3], board)){
                pq.push(-i);
                is_in[i] = false;
            }
        }
    }
    
    if(cnt > 0) return "IMPOSSIBLE";
    
    return answer;
}