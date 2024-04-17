#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, (int)gems.size()};
    
    set<string> kinds;
    for(string gem : gems){
        kinds.insert(gem);
    }
    
    int start = 0;
    int end = -1;
    map<string, int> buy;
    int num_kind = 0;
    while(end + 1 < gems.size()){ // end가 gem의 마지막에 도착하기 전까지 반복
        if(num_kind < kinds.size()){
            end++;
            buy[gems[end]]++;
            if(buy[gems[end]] == 1) num_kind++;
        }
        else{
            buy[gems[start]]--;
            if(buy[gems[start]] == 0) num_kind--;
            start++;
        }
        
        if(num_kind == kinds.size()){
            if(end - start < answer[1] - answer[0]){
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
        }
    }
    
    while(num_kind == kinds.size()){ // start를 1씩 증가하며 확인
        buy[gems[start]]--;
        if(buy[gems[start]] == 0) num_kind--;
        start++;
        
        if(num_kind == kinds.size()){
            if(end - start < answer[1] - answer[0]){
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
        }
    }
    
    return answer;
}