#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int search(int node, int& answer, vector<vector<vector<int>>>& edges){ // 자식의 모든 노드와의 거리 중 가장 긴 거리를 반환
    priority_queue<int> pq;
    for(vector<int> edge : edges[node]){
        pq.push(search(edge[0], answer, edges) + edge[1]);
    }

    int first = 0, second = 0;
    if(!pq.empty()){
        first = pq.top();
        pq.pop();
    }
    if(!pq.empty()) second = pq.top();

    answer = max(answer, first + second);
    return first;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<vector<int>>> edges(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b, g;
        cin >> a >> b >> g;

        edges[a].push_back({b, g});
    }

    int answer = 0;
    search(1, answer, edges);

    cout << answer;

    return 0;
}