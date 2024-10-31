#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, k;
queue<pair<int, int>> q;
vector<bool> visited;

void push(int num, int cnt){
    if(num < 0) return;
    while(num <= k){
        if(visited[num]) return;

        visited[num] = true;
        q.push({num, cnt});
        num *= 2;
    }

    if(visited[num]) return;

    visited[num] = true;
    q.push({num, cnt});
}

int main(){
    FASTIO

    cin >> n >> k;
    visited = vector<bool>(200'001, false);
    int answer;

    push(n, 0);
    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(now == k){
            answer = cnt;
            break;
        }

        push(now - 1, cnt + 1);
        push(now + 1, cnt + 1);
    }

    cout << answer;

    return 0;
}