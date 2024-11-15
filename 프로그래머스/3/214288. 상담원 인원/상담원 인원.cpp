#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<vector<int>, int> waiting_time;

int calc_waiting_time(vector<int>& counselors, vector<vector<int>>& reqs){
    auto iter = waiting_time.find(counselors);
    if(iter != waiting_time.end()) return (*iter).second;
    
    int res = 0;
    vector<priority_queue<int, vector<int>, greater<int>>> pqs(counselors.size()); // 각 상담마다 끝나는 시간을 넣음
    for(vector<int> req : reqs){
        int start_time = req[0];
        int counseling_time = req[1];
        int type = req[2] - 1;
        
        if(pqs[type].size() == counselors[type]){
            int prev_end_time = pqs[type].top();
            pqs[type].pop();
            
            if(start_time < prev_end_time){
                res += prev_end_time - start_time;
                start_time = prev_end_time;
            }
        }
        
        pqs[type].push(start_time + counseling_time);
    }
    
    waiting_time[counselors] = res;
    return res;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    vector<int> counselors(k, 1);
    
    for(int cnt = k; cnt < n; cnt++){
        int now_waiting_time = 987654321;
        int idx = 0;
        for(int i = 0; i < k; i++){
            counselors[i]++;
            int next_waiting_time = calc_waiting_time(counselors, reqs);
            counselors[i]--;
            
            if(now_waiting_time > next_waiting_time){
                now_waiting_time = next_waiting_time;
                idx = i;
            }
        }
        
        counselors[idx]++;
    }
    
    return calc_waiting_time(counselors, reqs);
}