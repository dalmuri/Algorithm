#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

pair<int, int> dir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n;

void check(int r, int c, int h, vector<vector<int>>& ground, vector<vector<bool>>& visited, int& min_h){
    if(ground[r][c] <= h) return;
    if(visited[r][c]) return;
    visited[r][c] = true;
    min_h = min(min_h, ground[r][c]);

    for(auto [dr, dc] : dir){
        int next_r = r + dr;
        int next_c = c + dc;

        if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) continue;
        check(next_r, next_c, h, ground, visited, min_h);
    }
}

int main(){
    FASTIO

    cin >> n;

    vector<vector<int>> ground(n, vector<int>(n));
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < n; ++c){
            cin >> ground[r][c];
        }
    }

    int answer = 0;
    for(int h = 0; h <= 100;){
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        int count = 0;
        int min_h = h + 1;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                if(ground[r][c] <= h) continue;
                if(visited[r][c]) continue;

                check(r, c, h, ground, visited, min_h);
                count++;
            }
        }

        answer = max(answer, count);
        if(count == 0) break;
        h = min_h;
    }

    cout << answer;

    return 0;
}