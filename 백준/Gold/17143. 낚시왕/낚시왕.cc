#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int r, c;
vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct shark{
    int speed, dir, size;

    shark(int speed, int dir, int size){
        this->speed = speed;
        this->dir = dir;
        this->size = size;
    }

    shark():shark(0, 0, 0){}

    bool operator<(const shark& other) const{
        return this->size < other.size;
    }

    bool operator>(const shark& other) const{
        return this->size > other.size;
    }
};

int try_fish(int col, vector<vector<shark>>& water){
    for(int row = 1; row <= r; row++){
        if(water[row][col].size > 0){
            int res = water[row][col].size;
            water[row][col].size = 0;

            return res;
        }
    }
    return 0;
}

void move_shark(int row, int col, vector<vector<shark>>& water, vector<vector<shark>>& next_water){
    if(water[row][col].size == 0) return;

    shark shk = water[row][col];
    int next_row = row + direction[shk.dir][0] * shk.speed;
    int next_col = col + direction[shk.dir][1] * shk.speed;

    while(next_row <= 0 || next_row > r){
        if(next_row <= 0) next_row = -next_row + 2;
        else next_row = 2 * r - next_row;
        shk.dir = (shk.dir + 2) % 4;
    }

    while(next_col <= 0 || next_col > c){
        if(next_col <= 0) next_col = -next_col + 2;
        else next_col = 2 * c - next_col;
        shk.dir = (shk.dir + 2) % 4;
    }

    next_water[next_row][next_col] = max(next_water[next_row][next_col], shk);
}

int main(){
    FASTIO

    int m;
    cin >> r >> c >> m;
    vector<vector<shark>> water(r + 1, vector<shark>(c + 1));
    for(int i = 0; i < m; i++){
        int row, col, s, d, z;
        cin >> row >> col >> s >> d >> z;

        if(d == 1) d = 0;
        else if(d == 2) d = 2;
        else if(d == 3) d = 1;
        else d = 3;

        water[row][col] = shark(s, d, z);
    }

    int answer = 0;
    for(int col = 1; col <= c; col++){
        answer += try_fish(col, water);

        vector<vector<shark>> next_water(r + 1, vector<shark>(c + 1));
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                move_shark(i, j, water, next_water);
            }
        }
        water = next_water;
    }

    cout << answer;

    return 0;
}