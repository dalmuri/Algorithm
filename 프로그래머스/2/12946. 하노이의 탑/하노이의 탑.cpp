#include <string>
#include <vector>

using namespace std;

void move(int disk, int now, int to_move, vector<vector<int>> &answer){
    if(disk == 0) return;
    
    move(disk - 1, now, 6 - now - to_move, answer);
    answer.push_back({now, to_move});
    move(disk - 1, 6 - now - to_move, to_move, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    move(n, 1, 3, answer);
    return answer;
}