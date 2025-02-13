#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

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

    priority_queue<tuple<int, int, int>> pq;
    for(int j = 0; j < n; j++) pq.push({table[n - 1][j], n - 1, j});

    int cnt = n;
    int num;
    while(cnt--){
        num = get<0>(pq.top());
        int r = get<1>(pq.top());
        int c = get<2>(pq.top());
        pq.pop();

        if(r > 0) pq.push({table[r - 1][c], r - 1, c});
    }

    cout << num;

    return 0;
}