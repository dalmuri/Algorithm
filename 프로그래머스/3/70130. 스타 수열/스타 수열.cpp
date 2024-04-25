#include <string>
#include <vector>
#include <map>

using namespace std;

int len_starseq(int num, vector<int>& a){
    int result = 0;
    for(int i = 0; i + 1 < a.size(); i++){
        if(a[i] != a[i + 1] && (a[i] == num || a[i + 1] == num)){
            result += 2;
            i++;
        }
    }
    
    return result;
}

int solution(vector<int> a) {
    map<int, int> counts;
    for(int num : a) counts[num]++;
    
    int answer = 0;
    for(auto iter = counts.begin(); iter != counts.end(); iter++){
        if(iter->second * 2 <= answer) continue;
        
        answer = max(answer, len_starseq(iter->first, a));
    }
    
    return answer;
}