#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for(int i = 0; i < n; i++) cin >> board[i];

    int answer = 64;
    for(int i = 0; i + 7 < n; i++){
        for(int j = 0; j + 7 < m; j++){
            int cnt = 0;
            for(int r = i; r < i + 8; r++){
                for(int c = j; c < j + 8; c++){
                    if((r + c - i - j) & 1){
                        if(board[i][j] == board[r][c]) cnt++;
                    }
                    else{
                        if(board[i][j] != board[r][c]) cnt++;
                    }
                }
            }

            answer = min(answer, min(cnt, 64 - cnt));
        }
    }

    cout << answer;

    return 0;
}