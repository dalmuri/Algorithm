#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<pair<int, int>> check = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(){
    FASTIO

    int n, a, b, m;
    cin >> n >> a >> b >> m;

    if(a > b) swap(a, b);

    vector<int> to_use(m);
    for(int i = 0; i < m; ++i) cin >> to_use[i];

    vector<vector<vector<int>>> doors(n + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX)));
    doors[a][b][0] = 0;
    
    queue<tuple<int, int, int>> q;
    q.push({a, b, 0});

    int answer = -1;

    while(!q.empty()){
        auto [open1, open2, progress] = q.front();
        q.pop();

        int count = doors[open1][open2][progress];
        while(progress < m && (open1 == to_use[progress] || open2 == to_use[progress]) && count + 1 < doors[open1][open2][progress + 1]){
            progress++;
            doors[open1][open2][progress] = count;
        }

        if(progress == m){answer = count; break;}
        
        for(auto [d1, d2] : check){
            int next1 = open1 + d1;
            int next2 = open2 + d2;

            if(1 <= next1 && next1 < next2 && next2 <= n){
                int next_progress = progress;
                if(next1 == to_use[progress] || next2 == to_use[progress]) next_progress++;

                if(doors[next1][next2][next_progress] > count + 1){
                    doors[next1][next2][next_progress] = count + 1;
                    q.push({next1, next2, next_progress});
                }
            }
        }
    }

    cout << answer;

    return 0;
}