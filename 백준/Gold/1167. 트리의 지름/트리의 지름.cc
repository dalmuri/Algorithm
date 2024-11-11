#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int search(int node, int parent, int& answer, vector<vector<vector<int>>>& tree){ // 자식의 모든 노드와의 거리 중 가장 긴 거리를 반환
    priority_queue<int> pq;
    for(vector<int> child : tree[node]){
        if(child[0] == parent) continue;
        pq.push(search(child[0], node, answer, tree) + child[1]);
    }

    int dist1 = 0, dist2 = 0;
    if(!pq.empty()){
        dist1 = pq.top();
        pq.pop();
    }
    if(!pq.empty()) dist2 = pq.top();

    answer = max(answer, dist1 + dist2);
    return dist1;
}

int main(){
    FASTIO

    int v;
    cin >> v;
    vector<vector<vector<int>>> tree(v + 1);

    for(int i = 0; i < v; i++){
        int node, vertex, edge;
        cin >> node >> vertex;
        while(vertex != -1){
            cin >> edge;
            tree[node].push_back({vertex, edge});
            cin >> vertex;
        }
    }

    int answer = 0;
    search(1, -1, answer, tree);
    cout << answer;

    return 0;
}