#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

pair<int, int> direction[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

struct fish{
    int num, dir;
    // num == 0 => 비어있음
    // num == -1 => 상어
};

pair<int, int> search_fish(int num, array<array<fish, 4>, 4>& aquarium){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(aquarium[i][j].num == num){
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

void move_fish(int r, int c, array<array<fish, 4>, 4>& aquarium){
    int dir = aquarium[r][c].dir;
    
    for(int i = 0; i < 8; i++){
        int now_dir = (dir + i) % 8;
        int next_r = r + direction[now_dir].first;
        int next_c = c + direction[now_dir].second;

        if(next_r < 0 || next_r >= 4 || next_c < 0 || next_c >= 4) continue;
        if(aquarium[next_r][next_c].num == -1) continue;

        aquarium[r][c].dir = now_dir;
        swap(aquarium[r][c], aquarium[next_r][next_c]);
        return;
    }
}

void move_fishes(array<array<fish, 4>, 4>& aquarium){
    for(int num = 1; num <= 16; num++){
        auto [r, c] = search_fish(num, aquarium);

        if(r < 0) continue;

        move_fish(r, c, aquarium);
    }
}

int move_shark(array<array<fish, 4>, 4>& aquarium){
    auto [r, c] = search_fish(-1, aquarium);
    int dir = aquarium[r][c].dir;

    int result = 0;
    for(int dist = 1; dist <= 3; dist++){
        int next_r = r + direction[dir].first * dist;
        int next_c = c + direction[dir].second * dist;

        if(next_r < 0 || next_r >= 4 || next_c < 0 || next_c >= 4) continue;
        if(aquarium[next_r][next_c].num == 0) continue;

        array<array<fish, 4>, 4> new_aquarium(aquarium);
        int feed = new_aquarium[next_r][next_c].num;
        new_aquarium[next_r][next_c].num = -1;
        new_aquarium[r][c].num = 0;
        move_fishes(new_aquarium);
        result = max(result, move_shark(new_aquarium) + feed);
    }

    return result;
}

void print(array<array<fish, 4>, 4>& aquarium){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << "(" << aquarium[i][j].num << " " << aquarium[i][j].dir << ") ";
        }
        cout << "\n";
    }
}

int main(){
    FASTIO

    array<array<fish, 4>, 4> aquarium;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int num, dir;
            cin >> num >> dir;

            aquarium[i][j] = {num, dir - 1};
        }
    }

    int answer = aquarium[0][0].num;
    aquarium[0][0].num = -1;
    move_fishes(aquarium);

    answer += move_shark(aquarium);
    cout << answer;

    return 0;
}