#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct node{
    bool is_sheep = true;
    int val = 0;
};

node nodes[123'457];
vector<int> edges[123'457];

long long calc(int num, int parent){
    long long result = 0ll;

    for(int child : edges[num]){
        if(child == parent) continue;

        result += calc(child, num);
    }

    if(nodes[num].is_sheep) result += nodes[num].val;
    else result = max(0ll, result - nodes[num].val);

    return result;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        char t;
        int a, p;
        cin >> t >> a >> p;

        nodes[i] = {(t == 'S'), a};
        edges[i].push_back(p);
        edges[p].push_back(i);
    }

    cout << calc(1, -1);

    return 0;
}