#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int n, vector<int> cores) {
    if(n <= cores.size()) return n;
    n -= cores.size();
    
    int left = 0;
    int right = *max_element(cores.begin(), cores.end()) * n;
    int time = right;
    while(left <= right){
        int mid = (left + right) / 2;
        int sum = accumulate(cores.begin(), cores.end(), 0, [&](int init, int e){ return init + mid / e; });
        
        if(n <= sum){
            time = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    int remain_work = n - accumulate(cores.begin(), cores.end(), 0, [&](int init, int e){
        return init + (time - 1) / e;
    });
    
    int answer = 0;
    for(int i = 0; i < cores.size(); i++){
        if(time % cores[i] == 0){
            remain_work--;
            
            if(remain_work == 0){
                answer = i + 1;
                break;
            }
        }
    }
    
    return answer;
}