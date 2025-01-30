#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int root[10'001];

int find_root(int day){
    if(root[day] == -1) return day;
    return root[day] = find_root(root[day]);
}

void union_root(int a, int b){
    int root_a = find_root(a);
    int root_b = find_root(b);

    root[max(root_a, root_b)] = min(root_a, root_b);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    fill(root, root + sizeof(root) / sizeof(int), -1);

    using pii = pair<int, int>;
    vector<pii> lectures(n);
    for(int i = 0; i < n; i++){
        int p, d;
        cin >> p >> d;

        lectures[i] = {p, d};
    }

    sort(lectures.begin(), lectures.end(), [](pii a, pii b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    int answer = 0;
    for(auto [pay, day] : lectures){
        int rt = find_root(day);
        if(rt == 0) continue;

        union_root(rt, rt - 1);
        answer += pay;
    }

    cout << answer;

    return 0;
}