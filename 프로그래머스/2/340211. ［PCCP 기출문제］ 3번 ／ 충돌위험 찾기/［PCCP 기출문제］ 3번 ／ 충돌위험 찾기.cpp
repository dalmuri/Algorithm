#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    map<tuple<int, int, int>, int> dict; // time, r, c
    for(vector<int> route : routes){
        vector<int> now = points[route[0] - 1];
        int time = 0;
        dict[{time, now[0], now[1]}]++;
        if(dict[{time, now[0], now[1]}] == 2) answer++;
        
        for(int i = 1; i < route.size(); i++){
            vector<int> next = points[route[i] - 1];
            while(now[0] != next[0] || now[1] != next[1]){
                time++;
                if(now[0] != next[0]){
                    if(now[0] < next[0]) now[0]++;
                    else now[0]--;
                    
                    dict[{time, now[0], now[1]}]++;
                    if(dict[{time, now[0], now[1]}] == 2) answer++;
                }
                else{
                    if(now[1] < next[1]) now[1]++;
                    else now[1]--;
                    
                    dict[{time, now[0], now[1]}]++;
                    if(dict[{time, now[0], now[1]}] == 2) answer++;
                }
            }
        }
    }
    
    return answer;
}