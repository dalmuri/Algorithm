#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void compress(vector<int>& universe){
    vector<int> temp(universe);

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0; i < universe.size(); ++i){
        universe[i] = lower_bound(temp.begin(), temp.end(), universe[i]) - temp.begin();
    }
}

int main(){
    FASTIO

    int m, n;
    cin >> m >> n;

    vector<vector<int>> universes(m, vector<int>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> universes[i][j];
        }

        compress(universes[i]);
    }

    int answer = 0;
    for(int i = 0; i + 1 < m; ++i){
        for(int j = i + 1; j < m; ++j){
            if(universes[i].size() != universes[j].size()) continue;

            bool flag = true;
            for(int k = 0; k < universes[i].size(); ++k){
                if(universes[i][k] != universes[j][k]){
                    flag = false;
                    break;
                }
            }

            if(flag) answer++;
        }
    }

    cout << answer;

    return 0;
}