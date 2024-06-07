#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void calc_sum(int idx, int sum, vector<int>& sums, vector<int>& comb, vector<vector<int>>& dice){
    if(idx == comb.size()){
        sums.push_back(sum);
        return;
    }
    
    for(int d : dice[comb[idx]]){
        calc_sum(idx + 1, sum + d, sums, comb, dice);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    vector<int> answer;
    int max_win = 0;
    
    vector<int> comb_tmp(n / 2, 0);
    for(int i = 0; i < n / 2; i++) comb_tmp.push_back(1);
    
    vector<vector<int>> combinations;
    do{
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            if(comb_tmp[i]) tmp.push_back(i);
        }
        combinations.push_back(tmp);
    }while(next_permutation(comb_tmp.begin(), comb_tmp.end()));
    
    for(int i = 0; i * 2 < combinations.size(); i++){
        vector<int> sum1;
        calc_sum(0, 0, sum1, combinations[i], dice);
        sort(sum1.begin(), sum1.end());
        
        vector<int> sum2;
        calc_sum(0, 0, sum2, combinations[(int)combinations.size() - 1 - i], dice);
        sort(sum2.begin(), sum2.end());
        
        int win1 = 0;
        for(int s : sum1) win1 += lower_bound(sum2.begin(), sum2.end(), s) - sum2.begin();
        
        int win2 = 0;
        for(int s : sum2) win2 += lower_bound(sum1.begin(), sum1.end(), s) - sum1.begin();
        
        if(win1 > win2){
            if(win1 > max_win){
                max_win = win1;
                answer = combinations[i];
            }
        }
        else{
            if(win2 > max_win){
                max_win = win2;
                answer = combinations[(int)combinations.size() - 1 - i];
            }
        }
    }
    
    for(int i = 0; i < answer.size(); i++) answer[i]++;
    return answer;
}