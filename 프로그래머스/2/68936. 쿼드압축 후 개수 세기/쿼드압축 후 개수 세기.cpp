#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> answer = {0, 0};

void check(int startRow, int startCol, int size, vector<vector<int>>& arr){
    if(size == 1){
        answer[arr[startRow][startCol]]++;
        return;
    }
    
    int num = arr[startRow][startCol];
    for(int r = startRow; r < startRow + size; r++){
        for(int c = startCol; c < startCol + size; c++){
            if(arr[r][c] == num) continue;
            
            check(startRow, startCol, size / 2, arr);
            check(startRow, startCol + size / 2, size / 2, arr);
            check(startRow + size / 2, startCol, size / 2, arr);
            check(startRow + size / 2, startCol + size / 2, size / 2, arr);
            return;
        }
    }
    
    answer[num]++;
}

vector<int> solution(vector<vector<int>> arr) {
    check(0, 0, arr.size(), arr);   
    
    return answer;
}