#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int main(){
    FASTIO

    int inf = 987654321;
    int n, m;
    cin >> n >> m;

    vector<int> move(101, 0);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        move[x] = y;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        move[x] = y;
    }

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; // {idx, cnt}
    vector<int> count(101, inf);
    count[1] = 0;
    pq.push({1, 0});
    while(!pq.empty()){
        int idx = pq.top()[0];
        int cnt = pq.top()[1];
        pq.pop();

        if(idx == 100) break;
        if(cnt > count[idx]) continue;

        for(int dice = 1; dice <= 6; dice++){
            int next = idx + dice;
            if(next > 100) continue;
            while(move[next] > 0) next = move[next];

            if(count[next] <= cnt + 1) continue;
            count[next] = cnt + 1;
            pq.push({next, cnt + 1});
        }
    }

    cout << count[100];

    return 0;
}