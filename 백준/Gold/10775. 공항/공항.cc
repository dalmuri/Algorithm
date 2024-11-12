#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> to_use;

int find_gate(int num){
    if(to_use[num] == num) return num;
    to_use[num] = find_gate(to_use[num]);
    return to_use[num];
}

void combine(int a, int b){
    int root_a = find_gate(a);
    int root_b = find_gate(b);

    to_use[max(root_a, root_b)] = min(root_a, root_b);
}

int main(){
    FASTIO

    int g, p;
    cin >> g >> p;
    to_use = vector<int>(g + 1);
    for(int i = 0; i <= g; i++) to_use[i] = i;

    int answer = 0;
    for(int i = 0; i < p; i++){
        int plane;
        cin >> plane;

        int to_use_gate = find_gate(plane);
        if(to_use_gate == 0) break;

        combine(to_use_gate, to_use_gate - 1);
        answer++;
    }

    cout << answer;

    return 0;
}