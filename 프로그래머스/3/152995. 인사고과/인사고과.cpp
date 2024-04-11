#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    vector<int> wanho(scores[0]);
    
    sort(scores.rbegin(), scores.rend(), [](vector<int> a, vector<int> b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    
    vector<int> grade = {scores[0][0] + scores[0][1]};
    int peer_max = -1;
    int now_peer_max = scores[0][1];
    int now_attitude = scores[0][0];
    for(int i = 1; i < scores.size(); i++){
        if(scores[i][0] != now_attitude){
            now_attitude = scores[i][0];
            peer_max = max(peer_max, now_peer_max);
        }
        
        now_peer_max = max(now_peer_max, scores[i][1]);
        if(wanho[0] <= now_attitude && wanho[1] < peer_max) return -1;
        if(scores[i][1] < peer_max) continue;
        
        grade.push_back(scores[i][0] + scores[i][1]);
    }
    
    sort(grade.rbegin(), grade.rend());
    return find(grade.begin(), grade.end(), wanho[0] + wanho[1]) - grade.begin() + 1;
}