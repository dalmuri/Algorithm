#include <string>
#include <vector>
#include <map>

using namespace std;

void allocate(int seller_idx, int profit, vector<int>& parents, vector<int>& answer){
    int to_give = profit / 10;
    int mine = profit - to_give;
    
    answer[seller_idx] += mine;
    if(parents[seller_idx] != -1 && to_give > 0) allocate(parents[seller_idx], to_give, parents, answer);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    map<string, int> idxs;
    vector<int> parents(enroll.size(), -1);
    for(int i = 0; i < enroll.size(); i++){
        idxs[enroll[i]] = i;
        
        if(referral[i] != "-") parents[i] = idxs[referral[i]];
    }
    
    vector<int> answer(enroll.size(), 0);
    for(int i = 0; i < seller.size(); i++) allocate(idxs[seller[i]], amount[i] * 100, parents, answer);
    
    return answer;
}