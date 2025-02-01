#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

using pii = pair<int, int>;

int root[200'001];

int get_root(int num){
    if(root[num] == -1) return num;
    return root[num] = get_root(root[num]);
}

void union_root(int a, int b){
    int root_a = get_root(a);
    int root_b = get_root(b);

    if(root_a < root_b) swap(root_a, root_b);
    root[root_a] = root_b;
}

int main(){
    FASTIO

    fill(root, root + sizeof(root) / sizeof(int), -1);

    int n;
    cin >> n;

    vector<pii> works(n);
    for(int i = 0; i < n; i++){
        int deadline, cup;
        cin >> deadline >> cup;

        works[i] = {cup, deadline};
    }

    sort(works.rbegin(), works.rend());

    int answer = 0;
    for(auto [cup, deadline] : works){
        int rt = get_root(deadline);
        if(rt == 0) continue;

        union_root(rt, rt - 1);
        answer += cup;
    }

    cout << answer;

    return 0;
}