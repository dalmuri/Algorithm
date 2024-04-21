#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b){ return a[1] < b[1]; });
    
    int answer = 1;
    int cam = routes[0][1];
    for(vector<int> route : routes){
        if(cam < route[0]){
            answer++;
            cam = route[1];
        }
    }
    return answer;
}