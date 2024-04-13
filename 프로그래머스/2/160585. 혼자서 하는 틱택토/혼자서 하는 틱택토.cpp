#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int numO = 0, numX = 0; // O, X의 개수
    bool winO = false, winX = false; // O, X가 승리했는지
    
    vector<int> rowO(3, 0), colO(3, 0), diagO(2, 0), rowX(3, 0), colX(3, 0), diagX(2, 0);
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'O'){
                numO++;
                rowO[i]++;
                colO[j]++;
                if(i == j) diagO[0]++;
                if(i + j == 2) diagO[1]++;
                
                if(rowO[i] == 3 || colO[j] == 3 || diagO[0] == 3 || diagO[1] == 3) winO = true;
            }
            else if(board[i][j] == 'X'){
                numX++;
                rowX[i]++;
                colX[j]++;
                if(i == j) diagX[0]++;
                if(i + j == 2) diagX[1]++;
                
                if(rowX[i] == 3 || colX[j] == 3 || diagX[0] == 3 || diagX[1] == 3) winX = true;
            }
        }
    }
    
    int diff = numO - numX;
    if(diff < 0 || diff > 1) return 0; // O와 X의 개수 문제
    if(winO && winX) return 0; // 둘 다 승리
    if(winO && diff == 0) return 0; // 선공이 승리했는데 개수 동일
    if(winX && diff == 1) return 0; // 후공이 승리했는데 개수 다름
    return 1;
}