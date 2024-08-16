#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int mod = 1'000'000'007;
    vector<vector<int>> roads(n + 1, vector<int>(m + 1, 0));
    roads[1][1] = 1;
    for(vector<int> puddle : puddles) roads[puddle[1]][puddle[0]] = -1;
    
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            if(roads[r][c] == -1) continue;
            if(roads[r - 1][c] != -1) roads[r][c] = (roads[r][c] + roads[r - 1][c]) % mod;
            if(roads[r][c - 1] != -1) roads[r][c] = (roads[r][c] + roads[r][c - 1]) % mod;
        }
    }
    return roads[n][m];
}