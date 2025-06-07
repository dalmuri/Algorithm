#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    //////////////////////////////////////////////////
    const int button[5] = {60, 10, -10, 1, -1};

    vector<bool> visited(121, false);
    visited[0] = true;

    queue<int> q;
    q.push(0);

    vector<vector<int>> cache(121, vector<int>(5, 0));
    while(!q.empty()){
        int time = q.front();
        q.pop();

        for(int i = 4; i >= 0; --i){
            int next_time = time + button[i];
            if(next_time <= 0 || next_time > 120) continue;
            if(visited[next_time]) continue;

            visited[next_time] = true;
            cache[next_time] = cache[time];
            cache[next_time][i]++;
            q.push(next_time);
        }
    }
    //////////////////////////////////////////////////
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << cache[n % 120][0] + n / 120 * 2 << " ";
        for(int i = 1; i < 5; ++i) cout << cache[n % 120][i] << " ";
        cout << "\n";
    }

    return 0;
}