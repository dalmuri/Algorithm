#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    // 콜라츠 추측 계산
    vector<int> collatz = {k};
    while(k > 1){
        if((k & 1) == 0) k /= 2;
        else k = k * 3 + 1;
        
        collatz.push_back(k);
    }
    
    // 길이 1의 구간마다 넓이 계산
    vector<double> areas;
    for(int i = 0; i + 1 < collatz.size(); i++){
        areas.push_back((double)(collatz[i] + collatz[i + 1]) / 2);
    }
    
    // 정답 계산
    vector<double> answer;
    for(vector<int> range : ranges){
        if(range[0] <= (int)areas.size() + range[1])
            answer.push_back(accumulate(areas.begin() + range[0], areas.end() + range[1], 0.0));
        else
            answer.push_back(-1.0);
    }
    
    return answer;
}