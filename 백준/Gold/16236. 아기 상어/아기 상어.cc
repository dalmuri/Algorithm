#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int inf = 987654321;
vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int n;
vector<vector<int>> space;

int eat(int& r, int& c, int shark){
    int fish_r = -1, fish_c = -1;

    vector<vector<int>> dist(n, vector<int>(n, inf));
    dist[r][c] = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()){
        int now_r = q.front().first;
        int now_c = q.front().second;
        q.pop();

        if(fish_r > -1 && dist[fish_r][fish_c] < dist[now_r][now_c]) break;
        if(fish_r > -1 && 0 < space[now_r][now_c] && space[now_r][now_c] < shark){
            if(now_r < fish_r || (now_r == fish_r && now_c < fish_c)){
                fish_r = now_r;
                fish_c = now_c;
            }
            continue;
        }
        if(0 < space[now_r][now_c] && space[now_r][now_c] < shark){
            fish_r = now_r;
            fish_c = now_c;
        }

        for(vector<int> d : dir){
            int next_r = now_r + d[0];
            int next_c = now_c + d[1];
            if(next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) continue;
            if(shark < space[next_r][next_c]) continue;
            if(dist[now_r][now_c] + 1 < dist[next_r][next_c]){
                dist[next_r][next_c] = dist[now_r][now_c] + 1;
                q.push({next_r, next_c});
            }
        }
    }

    if(fish_r == -1) return 0;
    r = fish_r;
    c = fish_c;
    space[r][c] = 0;
    return dist[r][c];
}

int main(){
    FASTIO

    cin >> n;

    space = vector<vector<int>>(n, vector<int>(n));
    int r, c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> space[i][j];
            if(space[i][j] == 9){
                r = i;
                c = j;
                space[i][j] = 0;
            }
        }
    }

    int shark = 2, to_eat = shark;
    int dist = eat(r, c, shark);
    int answer = 0;
    while(dist > 0){
        answer += dist;
        to_eat--;
        if(to_eat == 0) to_eat = ++shark;

        dist = eat(r, c, shark);
    }
    
    cout << answer;

    return 0;
}