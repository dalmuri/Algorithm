#include <string>
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[3] < b[3];
    }
};

int main(){
    FASTIO

    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int m, n;
    cin >> m >> n;

    vector<vector<int>> maps(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> maps[i][j];
    }

    vector<vector<int>> cnt(m, vector<int>(n, 0));
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({maps[0][0], 0, 0, 1}); // height, row, col, count

    while(!pq.empty()){
        int height = pq.top()[0];
        int row = pq.top()[1];
        int col = pq.top()[2];
        int count = pq.top()[3];
        pq.pop();

        if(cnt[row][col] > count) continue;
        cnt[row][col] = count;

        for(vector<int> d : dir){
            int next_row = row + d[0];
            int next_col = col + d[1];
            if(next_row < 0 || next_row >= m || next_col < 0 || next_col >= n) continue;
            if(maps[next_row][next_col] >= maps[row][col]) continue;

            cnt[next_row][next_col] += count;
            pq.push({maps[next_row][next_col], next_row, next_col, cnt[next_row][next_col]});
        }
    }

    cout << cnt[m - 1][n - 1];

    return 0;
}