#include <string>
#include <vector>

using namespace std;

long long calc_time(int level, vector<int>& diffs, vector<int>& times){
    long long res = 0;
    for(int i = 0; i < diffs.size(); i++){
        if(diffs[i] <= level) res += times[i];
        else{
            res += (diffs[i] - level + 1) * times[i];
            if(i > 0) res += (diffs[i] - level) * times[i - 1];
        }
    }
    
    return res;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1, right = 100'000;
    int answer = right;
    while(left <= right){
        int mid = (left + right) / 2;
        long long time = calc_time(mid, diffs, times);
        
        if(time <= limit){
            right = mid - 1;
            answer = mid;
        }
        else{
            left = mid + 1;
        }
    }
    
    return answer;
}