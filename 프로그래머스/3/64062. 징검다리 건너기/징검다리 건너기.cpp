#include <vector>
#include <deque>
#include <climits>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    deque<int> window; // idx 저장
    for(int i = 0; i < stones.size(); i++){
        while(!window.empty() && i - window.front() + 1 > k) window.pop_front(); // window 개수가 k개보다 많으면 pop_front
        while(!window.empty() && stones[window.back()] < stones[i]) window.pop_back(); // 현재 stone보다 작은 수를 모두 제거
        
        window.push_back(i);
        
        if(i + 1 >= k) answer = min(answer, stones[window.front()]);
    }
    return answer;
}