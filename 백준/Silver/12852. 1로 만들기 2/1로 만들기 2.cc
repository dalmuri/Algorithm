#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int inf = 987654321;
vector<vector<int>> cnt;

int main(){
    FASTIO

    int n;
    cin >> n;

    cnt = vector<vector<int>>(n + 1, vector<int>(2, inf));
    cnt[n][0] = 0;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(now == 1) break;

        if(now % 3 == 0 && cnt[now][0] + 1 < cnt[now / 3][0]){
            cnt[now / 3][0] = cnt[now][0] + 1;
            cnt[now / 3][1] = now;
            q.push(now / 3);
        }

        if(now % 2 == 0 && cnt[now][0] + 1 < cnt[now / 2][0]){
            cnt[now / 2][0] = cnt[now][0] + 1;
            cnt[now / 2][1] = now;
            q.push(now / 2);
        }

        if(cnt[now][0] + 1 < cnt[now - 1][0]){
            cnt[now - 1][0] = cnt[now][0] + 1;
            cnt[now - 1][1] = now;
            q.push(now - 1);
        }
    }

    cout << cnt[1][0] << "\n";
    stack<int> stk;
    stk.push(1);
    for(int i = 1; i < n; i = cnt[i][1]) stk.push(cnt[i][1]);
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    

    return 0;
}