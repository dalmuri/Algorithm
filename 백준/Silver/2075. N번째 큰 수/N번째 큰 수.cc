#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct number{
    int num, row, col;

    bool operator<(const number& other) const{
        return num < other.num;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> table(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> table[i][j];
        }
    }

    priority_queue<number> pq;
    for(int j = 0; j < n; j++) pq.push({table[n - 1][j], n - 1, j});

    int cnt = n;
    int num;
    while(cnt--){
        num = pq.top().num;
        int r = pq.top().row;
        int c = pq.top().col;
        pq.pop();

        if(r > 0) pq.push({table[r - 1][c], r - 1, c});
    }

    cout << num;

    return 0;
}