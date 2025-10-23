#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> tiles(n);
    for(int i = 0; i < n; ++i) cin >> tiles[i];
    
    int answer = 0;
    vector<string> answer_tile(k, string(k, '_'));
    for(int start_r = 0; start_r < k; ++start_r){
        for(int start_c = 0; start_c < k; ++start_c){
            vector<int> count(26, 0);

            for(int i = start_r; i < n; i+=k){
                for(int j = start_c; j < m; j+=k){
                    count[tiles[i][j] - 'A']++;
                }
            }

            auto max_iter = max_element(count.begin(), count.end());
            answer += (n / k) * (m / k) - *max_iter;
            answer_tile[start_r][start_c] = 'A' + (max_iter - count.begin());
        }
    }

    cout << answer << "\n";
    for(int i = 0; i < n / k; ++i){
        for(int row = 0; row < k; ++row){
            for(int j = 0; j < m / k; ++j){
                cout << answer_tile[row];
            }
            cout << "\n";
        }
    }

    return 0;
}