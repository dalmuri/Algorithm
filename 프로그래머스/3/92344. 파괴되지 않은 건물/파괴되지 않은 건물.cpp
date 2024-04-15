#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));
    for(vector<int> sk : skill){
        int degree = sk[5];
        if(sk[0] == 1) degree *= -1;
        
        prefix_sum[sk[1]][sk[2]] += degree;
        prefix_sum[sk[1]][sk[4] + 1] += -degree;
        prefix_sum[sk[3] + 1][sk[2]] += -degree;
        prefix_sum[sk[3] + 1][sk[4] + 1] += degree;
    }
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i > 0) prefix_sum[i][j] += prefix_sum[i - 1][j];
            if(j > 0) prefix_sum[i][j] += prefix_sum[i][j - 1];
            if(i > 0 && j > 0) prefix_sum[i][j] -= prefix_sum[i - 1][j - 1];
            
            if(prefix_sum[i][j] + board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}