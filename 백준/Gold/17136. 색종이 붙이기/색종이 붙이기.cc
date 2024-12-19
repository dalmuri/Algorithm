#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 101;
int paper[10][10];
bool filled[10][10];
int colored_paper[] = {0, 5, 5, 5, 5, 5};

bool get_next(int& row, int& col){
    col--;
    if(col < 0){
        row--;
        col = 9;
    }

    if(row >= 0) return true;
    return false;
}

bool can_fill(int r, int c, int size){
    if(colored_paper[size] <= 0) return false;

    for(int i = r; i > r - size; i--){
        for(int j = c; j > c - size; j--){
            if(filled[i][j]) return false;
        }
    }

    return true;
}

void fill_paper(int r, int c, int size, bool val){
    for(int i = r; i > r - size; i--){
        for(int j = c; j > c - size; j--){
            filled[i][j] = val;
        }
    }
}

void dfs(int r, int c, int cnt, int& answer){
    if(cnt >= answer) return;

    while(get_next(r, c)){
        if(paper[r][c] > 0 && !filled[r][c]) break;
    }

    if(r < 0){
        answer = min(answer, cnt);
        return;
    }

    for(int i = paper[r][c]; i > 0; i--){
        if(!can_fill(r, c, i)) continue;

        fill_paper(r, c, i, true);
        colored_paper[i]--;

        dfs(r, c, cnt + 1, answer);

        fill_paper(r, c, i, false);
        colored_paper[i]++;
    }
}

int main(){
    FASTIO

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> paper[i][j];

            if(paper[i][j] == 1 && i > 0 && j > 0)
                paper[i][j] = min({4, paper[i][j - 1], paper[i - 1][j], paper[i - 1][j - 1]}) + 1; 
        }
    }

    int answer = inf;
    dfs(9, 10, 0, answer);

    cout << (answer < inf ? answer : -1);

    return 0;
}