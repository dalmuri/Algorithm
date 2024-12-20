#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

array<int, 1001> root;

int get_root(int num){
    if(root[num] == num) return num;
    else return root[num] = get_root(root[num]);
}

void union_root(int a, int b){
    int root_a = get_root(a);
    int root_b = get_root(b);

    root[max(root_a, root_b)] = min(root_a, root_b);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> works(n);
    for(int i = 0; i < n; i++){
        int d, w;
        cin >> d >> w;

        works[i] = {d, w};
    }

    sort(works.begin(), works.end(), [](pair<int, int> a, pair<int, int> b){
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    for(int i = 0; i < root.size(); i++) root[i] = i;
    int answer = 0;

    for(auto [d, w] : works){
        int rt = get_root(d);
        if(rt == 0) continue;

        union_root(rt, rt - 1);
        answer += w;
    }

    cout << answer;

    return 0;
}