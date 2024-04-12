#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    vector<int> wanho(scores[0]);
    int wanho_score = wanho[0] + wanho[1];
    
    sort(scores.rbegin(), scores.rend(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });
    
    int answer = 1;
    int now_attitude = scores[0][0];
    int upper_peer_max = -1;
    int now_peer_max = -1;
    for(int i = 0; i < scores.size(); i++){
        if(scores[i][0] != now_attitude){
            now_attitude = scores[i][0];
            upper_peer_max = max(upper_peer_max, now_peer_max);
            
            if(wanho[0] <= now_attitude && wanho[1] < upper_peer_max) return -1;
        }
        
        now_peer_max = max(now_peer_max, scores[i][1]);
        if(scores[i][1] < upper_peer_max) continue;
        
        if(wanho_score < scores[i][0] + scores[i][1]) answer++;
    }

    return answer;
}