#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO


    int n, k;
    cin >> n >> k;

    vector<vector<int>> count(200'001, {200'001, 0});
    queue<vector<int>> q;
    count[n][0] = 0;
    q.push({n, 0});
    while(!q.empty()){
        int now = q.front()[0];
        int sec = q.front()[1];
        q.pop();

        if(count[k][1] > 0 && count[k][0] < sec) break;
        if(count[now][0] < sec) continue;

        count[now][1]++;

        if(now - 1 >= 0 && sec + 1 <= count[now - 1][0]){
            count[now - 1][0] = sec + 1;
            q.push({now - 1, sec + 1});
        }

        if(now + 1 < count.size() && sec + 1 <= count[now + 1][0]){
            count[now + 1][0] = sec + 1;
            q.push({now + 1, sec + 1});
        }

        if(now * 2 < count.size() && sec + 1 <= count[now * 2][0]){
            count[now * 2][0] = sec + 1;
            q.push({now * 2, sec + 1});
        }
    }

    cout << count[k][0] << "\n" << count[k][1];

    return 0;
}