#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct Log{
    int x1, x2, y, idx;
};

int root[100'001];
int get_root(int num){
    if(root[num] == 0) return num;
    return root[num] = get_root(root[num]);
}

void union_root(int a, int b){
    int root_a = get_root(a);
    int root_b = get_root(b);

    if(root_a == root_b) return;
    root[max(root_a, root_b)] = min(root_a, root_b);
}

int main(){
    FASTIO

    int n, q;
    cin >> n >> q;

    vector<Log> logs(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> logs[i].x1 >> logs[i].x2 >> logs[i].y;
        logs[i].idx = i;
    }

    sort(logs.begin() + 1, logs.end(), [](Log a, Log b){
        if(a.x1 != b.x1) return a.x1 < b.x1;
        return a.x2 < b.x2;
    });

    int last_x = logs[1].x2;
    for(int i = 2; i <= n; ++i){
        if(logs[i].x1 <= last_x) union_root(logs[i - 1].idx, logs[i].idx);

        last_x = max(last_x, logs[i].x2);
    }

    for(int i = 0; i < q; ++i){
        int q1, q2;
        cin >> q1 >> q2;

        if(get_root(q1) == get_root(q2)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}