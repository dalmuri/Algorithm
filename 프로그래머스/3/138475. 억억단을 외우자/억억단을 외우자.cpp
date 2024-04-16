#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> factors(e + 1, 1);
    for(int i = 2; i <= e; i++){
        for(int num = i; num <= e; num += i){
            factors[num]++;
        }
    }
    
    vector<int> dp(e + 1, e);
    for(int i = e - 1; i >= 1; i--){
        if(factors[dp[i + 1]] > factors[i])
            dp[i] = dp[i + 1];
        else
            dp[i] = i;
    }
    
    vector<int> answer;
    for(int start : starts) answer.push_back(dp[start]);
    
    return answer;
}