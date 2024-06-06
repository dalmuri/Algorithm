#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

void update(int al, int co, int val, int alp_req, int cop_req, vector<vector<int>>& dp){
    if(al > alp_req) al = alp_req;
    if(co > cop_req) co = cop_req;
    dp[al][co] = min(dp[al][co], val);
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int alp_req = alp;
    int cop_req = cop;
    for(vector<int> problem : problems){
        alp_req = max(alp_req, problem[0]);
        cop_req = max(cop_req, problem[1]);
    }
    
    vector<vector<int>> dp(alp_req + 1, vector<int>(cop_req + 1, INT_MAX)); // dp[i][j] = 알고력 i, 코딩력 j를 달성하기 위해 필요한 시간
    dp[alp][cop] = 0;
    
    for(int i = alp; i <= alp_req; i++){
        for(int j = cop; j <= cop_req; j++){
            update(i + 1, j, dp[i][j] + 1, alp_req, cop_req, dp);
            update(i, j + 1, dp[i][j] + 1, alp_req, cop_req, dp);
            for(vector<int> problem : problems){
                if(i < problem[0] || j < problem[1]) continue;
                update(i + problem[2], j + problem[3], dp[i][j] + problem[4], alp_req, cop_req, dp);
            }
        }
    }
    
    return dp[alp_req][cop_req];
}