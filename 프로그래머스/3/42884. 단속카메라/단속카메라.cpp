#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b){ return a[1] < b[1]; });
    
    int answer = 1;
    int cam = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(cam < routes[i][0]){
            answer++;
            cam = routes[i][1];
        }
        
    }
    
    return answer;
}