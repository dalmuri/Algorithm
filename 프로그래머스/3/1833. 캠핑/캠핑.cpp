#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> data) {
    sort(data.begin(), data.end(), [](vector<int> a, vector<int> b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
        });
    int answer = 0;
    
    for(int i = 0; i + 1 < data.size(); i++){
        for(int j = i + 1; j < data.size(); j++){
            if(data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
            bool can_tent = true;
            for(int k = i + 1; k < j; k++){
                if(data[i][0] < data[k][0] && data[k][0] < data[j][0] &&
                   min(data[i][1], data[j][1]) < data[k][1] && data[k][1] < max(data[i][1], data[j][1])){
                    can_tent = false;
                    break;
                }
            }
            
            if(can_tent) answer++;
        }
    }
    
    
    return answer;
}