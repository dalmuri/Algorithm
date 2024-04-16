#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> get_dist(){
    vector<vector<int>> coordinate = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2},{2, 0}, {2, 1}, {2, 2}};
    
    vector<vector<int>> dist(10, vector<int>(10, 1));
    for(int i = 0; i < 10; i++){
        for(int j = i; j < 10; j++){
            if(i == j) continue;
            
            int diff_r = abs(coordinate[i][0] - coordinate[j][0]);
            int diff_c = abs(coordinate[i][1] - coordinate[j][1]);
            
            int distance = 0;
            if(diff_r > 0 && diff_c > 0){
                int tmp = min(diff_r, diff_c);
                diff_r -= tmp;
                diff_c -= tmp;
                distance += tmp * 3;
            }
            
            if(diff_r > 0) distance += diff_r * 2;
            else if(diff_c > 0) distance += diff_c * 2;
            
            dist[i][j] = distance;
            dist[j][i] = distance;
        }
    }
    
    return dist;
}

int solution(string numbers) {
    vector<vector<int>> dist = get_dist(); // dist[i][j] = i에서 j로 이동해 누를 때의 가중치
    
    vector<vector<vector<int>>> weights(numbers.size() + 1, vector<vector<int>>(10, vector<int>(10, INT_MAX))); // weights[i + 1][l][r] = numbers[i]까지 누른 후 왼손과 오른손이 각각 l, r 위에 있을 때의 가중치 합의 최솟값
    weights[0][4][6] = 0;
    for(int i = 0; i < numbers.size(); i++){
        int now = i + 1;
        int num = numbers[i] - '0';
        
        for(int l = 0; l < 10; l++){
            for(int r = 0; r < 10; r++){
                if(weights[now - 1][l][r] == INT_MAX) continue;
                
                // 가만히
                if(l == num || r == num){
                    weights[now][l][r] = min(weights[now][l][r], weights[now - 1][l][r] + 1);
                    continue;
                }
                
                // 왼손 이동
                weights[now][num][r] = min(weights[now][num][r], weights[now - 1][l][r] + dist[l][num]);
                
                // 오른손 이동
                weights[now][l][num] = min(weights[now][l][num], weights[now - 1][l][r] + dist[r][num]);
            }
        }
    }
    
    vector<int> tmp_min(10);
    transform(weights[numbers.size()].begin(), weights[numbers.size()].end(), tmp_min.begin(), [](vector<int> a){
        return *min_element(a.begin(), a.end());
    });
    
    return *min_element(tmp_min.begin(), tmp_min.end());
}
