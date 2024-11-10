#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int r, c, t;
vector<vector<int>> room;
vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int air_cleaner; // 공기청정기의 아래쪽 행

void spread(){
    vector<vector<int>> next_room(r, vector<int>(c, 0));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] == 0) continue;

            int dust = room[i][j];
            for(vector<int> d : direction){
                int next_i = i + d[0];
                int next_j = j + d[1];
                if(next_i < 0 || next_i >= r || next_j < 0 || next_j >= c) continue;
                if(room[next_i][next_j] == -1) continue;

                next_room[next_i][next_j] += dust / 5;
                room[i][j] -= dust / 5;
            }
            next_room[i][j] += room[i][j];
        }
    }
    room = next_room;
}

void move_dust(int dir, int row, int col, int row_min, int row_max){
    for(; row_min <= row && row <= row_max && 0 <= col && col < c; row -= direction[dir][0], col -= direction[dir][1]){
        if(room[row][col] == -1) return;

        int dust = room[row][col];
        room[row][col] = 0;
        
        if(room[row + direction[dir][0]][col + direction[dir][1]] == -1) continue;
        room[row + direction[dir][0]][col + direction[dir][1]] = dust;
    }
}

void clean(){
    move_dust(2, air_cleaner - 2, 0, 0, air_cleaner - 1);
    move_dust(3, 0, 1, 0, air_cleaner - 1);
    move_dust(0, 1, c - 1, 0, air_cleaner - 1);
    move_dust(1, air_cleaner - 1, c - 2, 0, air_cleaner - 1);

    move_dust(0, air_cleaner + 1, 0, air_cleaner, r - 1);
    move_dust(3, r - 1, 1, air_cleaner, r - 1);
    move_dust(2, r - 2, c - 1, air_cleaner, r - 1);
    move_dust(1, air_cleaner, c - 2, air_cleaner, r - 1);
}

int main(){
    FASTIO

    cin >> r >> c >> t;
    
    room = vector<vector<int>>(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> room[i][j];

            if(room[i][j] == -1) air_cleaner = i;
        }
    }

    while(t--){
        spread();
        clean();
    }

    int answer = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] == -1) continue;

            answer += room[i][j];
        }
    }

    cout << answer;

    return 0;
}