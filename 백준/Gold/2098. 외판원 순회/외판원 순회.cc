#include <iostream>
#include <cstring>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 987654321

using namespace std;

int n;
int cost[16][16];
int info[16][1<<16];

int search(int city, int route){
    if(route == (1 << n) - 1){
        if(cost[city][0] == 0) return INF;
        return cost[city][0];
    }
    if(info[city][route] != -1) return info[city][route];
    
    info[city][route] = INF;
    for(int i = 0; i < n; i++){
        if(((1 << i) & route) != 0 || cost[city][i] == 0) continue;
        info[city][route] = min(info[city][route], search(i, route | (1 << i)) + cost[city][i]);
    }
    
    return info[city][route];
}

int main(){
    FASTIO;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }
    
    memset(info, -1, sizeof(info));
    
    cout << search(0, 1) << endl;
    
    return 0;
}