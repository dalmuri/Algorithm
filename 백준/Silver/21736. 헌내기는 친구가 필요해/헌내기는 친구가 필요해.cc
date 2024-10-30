#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<char>> campus;

int search(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= m) return 0;
    if(campus[r][c] == 'X') return 0;

    int result = 0;
    if(campus[r][c] == 'P') result++;
    campus[r][c] = 'X';
    
    for(vector<int> d : dir) result += search(r + d[0], c + d[1]);

    return result;
}

int main(){
    FASTIO

    cin >> n >> m;

    campus = vector<vector<char>>(n, vector<char>(m));
    int x, y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> campus[i][j];

            if(campus[i][j] == 'I'){
                x = i;
                y = j;
            }
        }
    }

    int answer = search(x, y);
    if(answer == 0) cout << "TT";
    else cout << answer;

    return 0;
}