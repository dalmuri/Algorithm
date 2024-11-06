#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> root;

int get_root(int num){
    if(root[num] == num) return num;

    root[num] = get_root(root[num]);
    return root[num];
}

bool union_root(int a, int b){
    int root_a = get_root(a);
    int root_b = get_root(b);

    if(root_a == root_b) return false;
    root[max(root_a, root_b)] = min(root_a, root_b);
    return true;
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    root = vector<int>(n);
    for(int i = 0; i < n; i++) root[i] = i;

    int answer = 0;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(!union_root(a, b)){
            answer = i;
            break;
        }
    }

    cout << answer;

    return 0;
}