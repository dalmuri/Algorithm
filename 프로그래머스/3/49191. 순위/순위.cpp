#include <string>
#include <vector>
#include <set>

using namespace std;

void search(int player, set<int>& others, vector<set<int>> &res){
    for(auto iter = res[player].begin(); iter != res[player].end(); iter++){
        if(others.find(*iter) == others.end()){
            others.insert(*iter);
            search(*iter, others, res);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<set<int>> wins(n + 1, set<int>()); // wins[i] = i선수를 이긴 선수 번호들
    vector<set<int>> loses(n + 1, set<int>()); // loses[i] = i선수에게 진 선수 번호들
    
    for(vector<int> result : results){
        wins[result[1]].insert(result[0]);
        loses[result[0]].insert(result[1]);
    }
    
    for(int i = 1; i <= n; i++){
        set<int> others;
        search(i, others, wins);
        search(i, others, loses);
        
        if(others.size() == n - 1) answer++;
    }
    
    return answer;
}