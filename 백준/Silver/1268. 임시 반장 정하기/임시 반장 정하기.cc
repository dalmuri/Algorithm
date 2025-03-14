#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> students(n, vector<int>(5));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> students[i][j];
        }
    }

    int max_cnt = 0;
    int answer = 1;
    for(int i = 0; i + 1 < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            for(int k = 0; k < 5; k++){
                if(students[i][k] == students[j][k]){
                    cnt++;
                    break;
                }
            }
        }

        if(max_cnt < cnt){
            max_cnt = cnt;
            answer = i + 1;
        }
    }

    cout << answer;

    return 0;
}