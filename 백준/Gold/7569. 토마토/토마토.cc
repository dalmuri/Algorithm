#include <string>
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<int>> dir = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int inf = 987654321;
struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[3] > b[3];
    }
};

bool able(int m, int n, int h, vector<vector<vector<int>>>& tomato){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < h; k++){
                if(tomato[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}

int main(){
    FASTIO

    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> tomato(m, vector<vector<int>>(n, vector<int>(h)));
    vector<vector<vector<int>>> days(m, vector<vector<int>>(n, vector<int>(h, inf)));
    queue<vector<int>> q;

    for(int k = 0; k < h; k++){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1) q.push({i, j, k, 0});
            }
        }
    }
    int answer = 0;

    while(!q.empty()){
        int row = q.front()[0];
        int col = q.front()[1];
        int hei = q.front()[2];
        int day = q.front()[3];
        q.pop();

        if(days[row][col][hei] <= day) continue;

        tomato[row][col][hei] = 1;
        days[row][col][hei] = day;
        answer = max(answer, day);
        for(vector<int> next : dir){
            int next_row = row + next[0];
            int next_col = col + next[1];
            int next_hei = hei + next[2];

            if(next_row < 0 || next_row >= m || next_col < 0 || next_col >= n || next_hei < 0 || next_hei >= h) continue;
            if(tomato[next_row][next_col][next_hei] != 0) continue;
            if(days[next_row][next_col][next_hei] <= day + 1) continue;

            q.push({next_row, next_col, next_hei, day + 1});
        }
    }

    if(able(m, n, h, tomato)) cout << answer;
    else cout << -1;

    return 0;
}