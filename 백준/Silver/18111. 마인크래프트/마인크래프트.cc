#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> ground(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> ground[i][j];
    }

    vector<int> answer = {INT_MAX, -1}; // time, height
    for(int h = 0; h <= 256; h++){
        int time = 0;
        long long block = b;
        bool flag = true;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(ground[r][c] > h){
                    time += 2 * (ground[r][c] - h);
                    block += ground[r][c] - h;
                }
            }
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(ground[r][c] < h){
                    if(block >= h - ground[r][c]){
                        time += h - ground[r][c];
                        block -= h - ground[r][c];
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }

        if(flag && time <= answer[0]){
            answer[0] = time;
            answer[1] = h;
        }
    }

    cout << answer[0] << " " << answer[1];

    return 0;
}