#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool visited[61][61][61];

int attack[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

struct scv{
    int a, b, c, cnt;
};

int main(){
    FASTIO

    const int inf = 987654321;

    int n;
    cin >> n;

    vector<int> init(3, 0);
    for(int i = 0; i < n; i++) cin >> init[i];
    
    sort(init.rbegin(), init.rend());

    queue<scv> q;
    q.push({init[0], init[1], init[2], 0});
    visited[init[0]][init[1]][init[2]] = true;

    int answer = 0;
    while(!q.empty()){
        scv now = q.front();
        q.pop();

        if(now.a == 0){
            answer = now.cnt;
            break;
        }

        for(int i = 0; i < 6; i++){
            scv next = {max(0, now.a - attack[i][0]), max(0, now.b - attack[i][1]), max(0, now.c - attack[i][2]), now.cnt + 1};

            if(next.a < next.b) swap(next.a, next.b);
            if(next.a < next.c) swap(next.a, next.c);
            if(next.b < next.c) swap(next.b, next.c);

            if(visited[next.a][next.b][next.c]) continue;
            visited[next.a][next.b][next.c] = true;

            q.push(next);
        }
    }

    cout << answer;

    return 0;
}