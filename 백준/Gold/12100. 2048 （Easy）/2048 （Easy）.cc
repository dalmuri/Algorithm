#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;

int move(int dir, vector<vector<int>>& board){
    int max_num = 0;
    if(dir == 0){ // up
        for(int c = 0; c < n; c++){
            vector<int> tmp;
            int combined = 0;
            for(int r = 0; r < n; r++){
                if(board[r][c] != 0){
                    if(combined < tmp.size() && !tmp.empty() && tmp.back() == board[r][c]){
                        tmp[tmp.size() - 1] *= 2;
                        combined = tmp.size();
                        continue;
                    }
                    tmp.push_back(board[r][c]);
                }
            }
            
            for(int r = 0; r < n; r++){
                if(r < tmp.size()) board[r][c] = tmp[r];
                else board[r][c] = 0;

                max_num = max(max_num, board[r][c]);
            }
        }
    }
    else if(dir == 1){ // right
        for(int r = 0; r < n; r++){
            vector<int> tmp;
            int combined = 0;
            for(int c = n - 1; c >= 0; c--){
                if(board[r][c] != 0){
                    if(combined < tmp.size() && !tmp.empty() && tmp.back() == board[r][c]){
                        tmp[tmp.size() - 1] *= 2;
                        combined = tmp.size();
                        continue;
                    }
                    tmp.push_back(board[r][c]);
                }
            }

            for(int c = 0; c < n; c++){
                if(c < tmp.size()) board[r][n - 1 - c] = tmp[c];
                else board[r][n - 1 - c] = 0;

                max_num = max(max_num, board[r][n - 1 - c]);
            }
        }
    }
    else if(dir == 2){ // down
        for(int c = 0; c < n; c++){
            vector<int> tmp;
            int combined = 0;
            for(int r = n - 1; r >= 0; r--){
                if(board[r][c] != 0){
                    if(combined < tmp.size() && !tmp.empty() && tmp.back() == board[r][c]){
                        tmp[tmp.size() - 1] *= 2;
                        combined = tmp.size();
                        continue;
                    }
                    tmp.push_back(board[r][c]);
                }
            }

            for(int r = 0; r < n; r++){
                if(r < tmp.size()) board[n - 1 - r][c] = tmp[r];
                else board[n - 1 - r][c] = 0;

                max_num = max(max_num, board[n - 1 - r][c]);
            }
        }
    }
    else if(dir == 3){ // left
        for(int r = 0; r < n; r++){
            vector<int> tmp;
            int combined = 0;
            for(int c = 0; c < n; c++){
                if(board[r][c] != 0){
                    if(combined < tmp.size() && !tmp.empty() && tmp.back() == board[r][c]){
                        tmp[tmp.size() - 1] *= 2;
                        combined = tmp.size();
                        continue;
                    }
                    tmp.push_back(board[r][c]);
                }
            }

            for(int c = 0; c < n; c++){
                if(c < tmp.size()) board[r][c] = tmp[c];
                else board[r][c] = 0;

                max_num = max(max_num, board[r][c]);
            }
        }
    }

    return max_num;
}

void search(int cnt, int& max_num, vector<vector<int>>& board){
    if(cnt == 0) return;

    for(int dir = 0; dir < 4; dir++){
        vector<vector<int>> new_board(board);
        int now_max = move(dir, new_board);
        if((now_max << (cnt - 1)) > max_num){
            max_num = max(max_num, now_max);
            search(cnt - 1, max_num, new_board);
        }
    }
}

int main(){
    FASTIO

    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    int answer = 0;
    search(5, answer, board);

    cout << answer;

    return 0;
}