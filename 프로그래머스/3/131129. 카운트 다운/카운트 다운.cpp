#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<vector<int>> points(target + 1, {100'001, -1});
    points[0][0] = 0;
    points[0][1] = 0;
    
    for(int n = 0; n <= target; n++){
        // 싱글
        for(int i = 1; i <= 20; i++){
            if(n + i > target) break;
            
            if(points[n + i][0] > points[n][0] + 1 || (points[n + i][0] == points[n][0] + 1 && points[n + i][1] < points[n][1] + 1)){
                points[n + i][0] = points[n][0] + 1;
                points[n + i][1] = points[n][1] + 1;
            }
        }
        
        // 더블
        for(int i = 2; i <= 40; i += 2){
            if(n + i > target) break;
            
            if(points[n + i][0] > points[n][0] + 1 || (points[n + i][0] == points[n][0] + 1 && points[n + i][1] < points[n][1])){
                points[n + i][0] = points[n][0] + 1;
                points[n + i][1] = points[n][1];
            }
        }
        
        // 트리플
        for(int i = 3; i <= 60; i += 3){
            if(n + i > target) break;
            
            if(points[n + i][0] > points[n][0] + 1 || (points[n + i][0] == points[n][0] + 1 && points[n + i][1] < points[n][1])){
                points[n + i][0] = points[n][0] + 1;
                points[n + i][1] = points[n][1];
            }
        }
        
        // 불
        if(n + 50 > target) continue;
        
        if(points[n + 50][0] > points[n][0] + 1 || (points[n + 50][0] == points[n][0] + 1 && points[n + 50][1] < points[n][1] + 1)){
            points[n + 50][0] = points[n][0] + 1;
            points[n + 50][1] = points[n][1] + 1;
        }
    }
    
    return points[target];
}