#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.rbegin(), dist.rend());
    vector<int> weaks(weak);
    for(int w : weak) weaks.push_back(w + n);
    
    for(int cnt = 1; cnt <= min(weak.size(), dist.size()); cnt++){ // cnt = 친구 수
        vector<int> chk(weak.size() - cnt, 0); // 친구들이 출발할 위치를 1로 표시
        for(int i = 0; i < cnt; i++) chk.push_back(1);
        
        do{
            vector<int> idxs; // 친구들이 출발할 위치 index
            for(int i = 0; i < chk.size(); i++){
                if(chk[i] == 1) idxs.push_back(i);
            }
            idxs.push_back(idxs[0] + weak.size());
            
            priority_queue<int> move; // 친구들이 각각 이동해야 하는 거리, 내림차순
            for(int i = 0; i + 1 < idxs.size(); i++) move.push(weaks[idxs[i + 1] - 1] - weaks[idxs[i]]);
            
            bool able = true;
            for(int i = 0; !move.empty(); i++){
                if(dist[i] < move.top()){ // 이동해야 하는 거리보다 짧게 이동하면
                    able = false;
                    break;
                }
                move.pop();
            }
            if(able) return cnt;
        }while(next_permutation(chk.begin(), chk.end()));
    }
    return -1;
}