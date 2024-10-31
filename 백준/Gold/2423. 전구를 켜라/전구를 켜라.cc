#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;

int turn(int r, int c, int dr, int dc, vector<vector<char>>& circuit){
    if(dr == 1 && dc == 1){
        if(circuit[r][c] == '\\') return 0;
        else return 1;
    }
    else if(dr == 1 && dc == -1){
        if(circuit[r][c - 1] == '/') return 0;
        else return 1;
    }
    else if(dr == -1 && dc == 1){
        if(circuit[r - 1][c] == '/') return 0;
        else return 1;
    }
    else{
        if(circuit[r - 1][c - 1] == '\\') return 0;
        else return 1;
    }
}

int main(){
    FASTIO

    int inf = 98765432;
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    cin >> n >> m;

    vector<vector<char>> circuit(n + 1, vector<char>(m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> circuit[i][j];
        }
    }
    if((n + m) & 1){
        cout << "NO SOLUTION";
        return 0;
    }

    vector<vector<int>> count(n + 1, vector<int>(m + 1, inf));
    count[0][0] = 0;

    deque<pair<int, int>> deq;
    deq.push_back({0, 0});
    while(!deq.empty()){
        int r = deq.front().first;
        int c = deq.front().second;
        deq.pop_front();

        if(r == n && c == m) break;

        for(vector<int> d : dir){
            int next_r = r + d[0];
            int next_c = c + d[1];
            if(next_r < 0 || next_r > n || next_c < 0 || next_c > m) continue;

            int to_turn = turn(r, c, d[0], d[1], circuit);
            if(count[r][c] + to_turn < count[next_r][next_c]){
                count[next_r][next_c] = count[r][c] + to_turn;
                if(to_turn == 0) deq.push_front({next_r, next_c});
                else deq.push_back({next_r, next_c});
            }
        }
    }

    cout << count[n][m];

    return 0;
}