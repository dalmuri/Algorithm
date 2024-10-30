#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n;
vector<vector<char>> houses;
vector<vector<bool>> visited;

int count(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n) return 0;
    if(houses[r][c] == '0') return 0;
    if(visited[r][c]) return 0;

    visited[r][c] = true;

    int result = 1;
    for(vector<int> d : dir) result += count(r + d[0], c + d[1]);
    
    return result;
}

int main(){
    FASTIO

    cin >> n;
    houses = vector<vector<char>>(n, vector<char>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> houses[i][j];
        }
    }

    vector<int> answer;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(houses[i][j] == '1' && !visited[i][j]) answer.push_back(count(i, j));
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for(int ans : answer) cout << ans << "\n";

    return 0;
}