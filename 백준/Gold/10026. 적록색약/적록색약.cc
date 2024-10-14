#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void visit(int row, int col, char color, int n, vector<vector<bool>>& visited, vector<vector<char>>& image){
    if(row < 0 || row >= n || col < 0 || col >= n) return;
    if(visited[row][col]) return;
    if(image[row][col] != color) return;

    visited[row][col] = true;

    for(vector<int> d : dir){
        visit(row + d[0], col + d[1], color, n, visited, image);
    }
}

int count(int n, vector<vector<char>>& image){
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) continue;

            visit(i, j, image[i][j], n, visited, image);
            result++;
        }
    }

    return result;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<char>> image1(n, vector<char>(n));
    vector<vector<char>> image2(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> image1[i][j];
            image2[i][j] = image1[i][j];
            if(image2[i][j] == 'G') image2[i][j] = 'R';
        }
    }

    cout << count(n, image1) << " " << count(n, image2);

    return 0;
}