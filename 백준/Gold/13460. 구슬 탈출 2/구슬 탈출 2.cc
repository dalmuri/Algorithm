#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> board;

int move(int dir, pair<int, int>& red, pair<int, int>& blue){
    bool moved = true;
    bool exits_red = false;
    while(moved){
        moved = false;
        
        int next_red_r = red.first + direction[dir][0];
        int next_red_c = red.second + direction[dir][1];
        if(board[next_red_r][next_red_c] != '#' && !exits_red){
            if((board[next_red_r][next_red_c] == '.' || board[next_red_r][next_red_c] == 'O') && (next_red_r != blue.first || next_red_c != blue.second)){
                if(board[next_red_r][next_red_c] == 'O') exits_red = true;
                red.first = next_red_r;
                red.second = next_red_c;
                moved = true;
            }
        }

        int next_blue_r = blue.first + direction[dir][0];
        int next_blue_c = blue.second + direction[dir][1];
        if(board[next_blue_r][next_blue_c] != '#'){
            if(board[next_blue_r][next_blue_c] == 'O') return -1;
            if(board[next_blue_r][next_blue_c] == '.' && (next_blue_r != red.first || next_blue_c != red.second)){
                blue.first = next_blue_r;
                blue.second = next_blue_c;
                moved = true;
            }
        }
    }

    if(exits_red) return 1;
    return 0;
}

int main(){
    FASTIO

    cin >> n >> m;

    board = vector<string>(n);
    pair<int, int> red, blue;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];

            if(board[i][j] == 'R'){
                red = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B'){
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    int answer = 0;
    queue<tuple<int, pair<int, int>, pair<int, int>, int>> q;
    q.push({1, red, blue, -1});
    while(!q.empty() && answer == 0){
        int cnt = get<0>(q.front());
        pair<int, int> r = get<1>(q.front());
        pair<int, int> b = get<2>(q.front());
        int prev = get<3>(q.front());
        q.pop();

        if(cnt > 10) break;

        for(int d = 0; d < 4; d++){
            if(d == prev) continue;
            pair<int, int> next_r(r);
            pair<int, int> next_b(b);
            int res = move(d, next_r, next_b);
            if(res < 0) continue;
            if(res > 0){
                answer = cnt;
                break;
            }

            q.push({cnt + 1, next_r, next_b, d});
        }
    }

    cout << (answer > 0 ? answer : -1);

    return 0;
}