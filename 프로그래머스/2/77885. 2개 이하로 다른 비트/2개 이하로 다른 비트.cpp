#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long num : numbers){
        for(long long i=1; true; i<<=1){
            if((num & i) == 0){
                answer.push_back(num + 1 + ((i-1) >> 1));
                break;
            }
        }
    }

    return answer;
}