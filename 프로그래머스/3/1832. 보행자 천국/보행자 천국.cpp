#include <vector>

using namespace std;

int MOD = 20170805;
vector<vector<int>> direction = {{0, 1}, {1, 0}}; // 우 하

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<vector<int>>> path(m, vector<vector<int>>(n, vector<int>(2, 0)));
    path[m - 1][n - 1][0] = 1;
    path[m - 1][n - 1][1] = 1;
    for(int r = m - 1; r >= 0; r--){
        for(int c = n - 1; c >= 0; c--){
            if(r == m - 1 && c == n - 1) continue;
            if(city_map[r][c] == 1) continue; // 자동차 통행 금지
            if(city_map[r][c] == 2){ // 회전 금지
                if(r < m - 1){
                    path[r][c][0] = path[r + 1][c][0];
                }
                if(c < n - 1){
                    path[r][c][1] = path[r][c + 1][1];
                }
            }
            else{ // 자유 통행
                int cnt = 0;
                if(r < m - 1){
                    cnt = (cnt + path[r + 1][c][0]) % MOD;
                }
                if(c < n - 1){
                    cnt = (cnt + path[r][c + 1][1]) % MOD;
                }
                path[r][c][0] = cnt;
                path[r][c][1] = cnt;
            }
        }
    }
    
    return path[0][0][0];
}