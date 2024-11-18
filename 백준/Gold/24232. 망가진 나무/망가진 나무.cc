#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct line{
    int node;
    bool forward;
    int idx;
};

int n;
vector<line> edges[100'001];
bool flips[99'999];
bool answer[99'999];
int min_cnt = 987654321;

int get_flip_cnt(int node, int parent){
    int cnt = 0;
    for(line child : edges[node]){
        if(child.node == parent) continue;

        if(!child.forward){
            flips[child.idx] = true;
            cnt++;
        }

        cnt += get_flip_cnt(child.node, node);
    }

    return cnt;
}

void dfs(int node, int parent, int cnt){
    if(min_cnt > cnt){
        min_cnt = cnt;
        copy(flips, flips + n - 1, answer);
    }

    for(line child : edges[node]){
        if(child.node == parent) continue;

        if(child.forward){
            flips[child.idx] = true;
            dfs(child.node, node, cnt + 1);
            flips[child.idx] = false;
        }
        else{
            flips[child.idx] = false;
            dfs(child.node, node, cnt - 1);
            flips[child.idx] = true;
        }
    }
}

int main(){
    FASTIO

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        edges[u].push_back({v, 1, i});
        edges[v].push_back({u, 0, i});
    }

    dfs(1, -1, get_flip_cnt(1, -1));

    for(int i = 0; i < n - 1; i++) cout << answer[i];

    return 0;
}