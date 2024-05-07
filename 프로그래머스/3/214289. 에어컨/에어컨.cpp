#include <vector>
#include <algorithm>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int inf = 1'000'000;
    int target = max(temperature - t2, t1 - temperature);
    vector<vector<int>> cost(onboard.size(), vector<int>(target + 2, inf));
    // cost[i][j] = i시각에 j온도가 되기 위한 최소 비용
    cost[0][0] = 0;
    
    for(int i = 1; i < onboard.size(); i++){
        int start = onboard[i] ? target : 0;
        for(int j = start; j <= target + 1; j++){
            // 에어컨 ON, 1도 상승
            if(j > 0) cost[i][j] = min(cost[i][j], cost[i - 1][j - 1] + a);
            
            // 온도 유지
            cost[i][j] = min(cost[i][j], j == 0 ? cost[i - 1][j] : cost[i - 1][j] + b);
            
            // 에어컨 OFF, 1도 하강
            if(j < target + 1) cost[i][j] = min(cost[i][j], cost[i - 1][j + 1]);
        }
    }
    
    return *min_element(cost[onboard.size() - 1].begin(), cost[onboard.size() - 1].end());
}