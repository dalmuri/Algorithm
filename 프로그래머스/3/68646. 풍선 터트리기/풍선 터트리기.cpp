#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    if(a.size() <= 2) return a.size();
    
    int answer = 2;
    
    vector<int> right_min(a.size(), 1000000001);
    right_min[a.size() - 1] = a[a.size() - 1];
    for(int i = a.size() - 2; i > 0; i--) right_min[i] = min(right_min[i + 1], a[i + 1]);
    
    int left_min = 1000000001;
    for(int i = 1; i < a.size() - 1; i++){
        left_min = min(left_min, a[i - 1]);
        
        if(a[i] <= left_min || a[i] <= right_min[i]) answer++;
    }
    
    return answer;
}