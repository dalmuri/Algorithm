#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int n, vector<int> cores) {
    if(n <= cores.size()) return n;
    n -= cores.size();
    
    int left = 0;
    int right = n * *max_element(cores.begin(), cores.end());
    int time = right;
    while(left <= right){
        int mid = (left + right) / 2;
        int sum = accumulate(cores.begin(), cores.end(), 0, [&mid](int acc, int now){ return acc + mid / now; });
        
        if(n <= sum){
            right = mid - 1;
            time = mid;
        }
        else{
            left = mid + 1;
        }
    }
    int answer = 0;
    int left_work = n - accumulate(cores.begin(), cores.end(), 0, [&time](int acc, int now){ return acc + (time - 1) / now; });
    for(int i = 0; i < cores.size(); i++){
        if(time % cores[i] == 0){
            left_work--;
            if(left_work == 0){
                answer = i + 1;
                break;
            }
        }
    }
    
    return answer;
}