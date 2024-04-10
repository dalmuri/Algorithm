#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int i = 0;
    priority_queue<int> defence;
    
    for(; i < enemy.size(); i++){
        n -= enemy[i];
        defence.push(enemy[i]);
        
        if(n < 0){
            if(k <= 0) break;
            
            k--;
            n += defence.top();
            defence.pop();
        }
    }
    return i;
}