#include <string>
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int main(){
    FASTIO

    int inf = 500'000'000;
    int n, m, start, dest;
    cin >> n >> m;

    vector<vector<vector<int>>> costs(n + 1, vector<vector<int>>());
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        costs[a].push_back({b, c});
    }

    cin >> start >> dest;

    vector<int> dist(n + 1, inf);
    dist[start] = 0;

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({start, 0});

    while(!pq.empty()){
        int now = pq.top()[0];
        int cost = pq.top()[1];
        pq.pop();

        if(cost > dist[now]) continue;
        for(vector<int> city : costs[now]){
            int next = city[0];
            int next_dist = cost + city[1];
            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next, next_dist});
            }
        }
    }

    cout << dist[dest];

    return 0;
}