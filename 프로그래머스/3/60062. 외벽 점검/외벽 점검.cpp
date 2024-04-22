#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.rbegin(), dist.rend());
    
    vector<int> weaks(weak);
    for(int w : weak) weaks.push_back(w + n);
    
    for(int cnt = 1; cnt <= min(weak.size(), dist.size()); cnt++){
        vector<int> nCr(weak.size() - cnt, 0);
        for(int i = 0; i < cnt; i++) nCr.push_back(1);
        
        do{
            vector<int> idxs;
            for(int i = 0; i < nCr.size(); i++){
                if(nCr[i] == 1) idxs.push_back(i);
            }
            idxs.push_back(idxs[0] + weak.size());
            
            priority_queue<int> weak_dist;
            for(int i = 0; i + 1 < idxs.size(); i++){
                weak_dist.push(weaks[idxs[i + 1] - 1] - weaks[idxs[i]]);
            }
            
            bool able = true;
            for(int d = 0; !weak_dist.empty() && d < dist.size(); d++){
                if(dist[d] < weak_dist.top()){
                    able = false;
                    break;
                }
                
                weak_dist.pop();
            }
            if(able) return cnt;
        }while(next_permutation(nCr.begin(), nCr.end()));
    }
    
    return -1;
}