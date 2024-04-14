#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> method(n + 1, 0);
    method[0] = 1;
    
    for(int coin : money){
        for(int i = coin; i <= n; i++){
            method[i] += method[i - coin];
        }
    }
    
    return method[n];
}