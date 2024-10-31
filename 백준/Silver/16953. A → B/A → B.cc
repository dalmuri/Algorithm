#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int a, b;
    cin >> a >> b;

    queue<pair<long long, int>> q;
    q.push({a, 1});
    int answer = -1;
    while(!q.empty()){
        long long num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(num == b){
            answer = cnt;
            break;
        }
        if(num > b) continue;

        q.push({num * 2, cnt + 1});
        q.push({num * 10 + 1, cnt + 1});
    }

    cout << answer;

    return 0;
}