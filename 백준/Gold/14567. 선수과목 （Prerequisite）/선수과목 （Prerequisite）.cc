#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<vector<int>> next(n + 1);
    vector<int> pre(n + 1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        pre[b]++;
        next[a].push_back(b);
    }

    queue<int> take;
    for(int i = 1; i <= n; i++){
        if(pre[i] == 0) take.push(i);
    }

    vector<int> answer(n + 1);
    int semester = 1;
    while(!take.empty()){
        int cnt = take.size();
        for(int i = 0; i < cnt; i++){
            int c = take.front();
            take.pop();

            answer[c] = semester;
            for(int j : next[c]){
                pre[j]--;
                if(pre[j] == 0) take.push(j);
            }
        }
        semester++;
    }

    for(int i = 1; i <= n; i++) cout << answer[i] << " ";

    return 0;
}