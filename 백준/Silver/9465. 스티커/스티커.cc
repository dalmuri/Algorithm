#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); // iostream과 stdio의 동기화를 비활성화. single thread 환경에서만 사용하자.
	cin.tie(NULL); // cin과 cout의 순서를 보장하지 않음
    
    int t;
    cin >> t;
    
    for(int tmp = 0; tmp < t; tmp++){
        int n;
        cin >> n;
        vector<vector<int>> stickers(2, vector<int>(n, 0)); // stickers[i][j] = i행 j열의 점수
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> stickers[i][j];
            }
        }
        
        if(n == 1){
            cout << max(stickers[0][0], stickers[1][0]) << "\n";
            continue;
        }
        
        vector<vector<int>> point(2, vector<int>(n, 0));
        
        point[0][0] = stickers[0][0];
        point[1][0] = stickers[1][0];
        point[0][1] = stickers[1][0] + stickers[0][1];
        point[1][1] = stickers[0][0] + stickers[1][1];
        
        for(int j = 2; j < n; j++){
            point[0][j] = max(point[1][j - 2], point[1][j - 1]) + stickers[0][j];
            point[1][j] = max(point[0][j - 2], point[0][j - 1]) + stickers[1][j];
        }
        
        cout << max(point[0][n - 1], point[1][n - 1]) << "\n";
    }
    
    return 0;
}