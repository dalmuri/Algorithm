#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int inf = 987654321;
vector<vector<vector<int>>> bus;
vector<int> dist;
vector<int> prv;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({start, 0});
    while(!pq.empty()){
        int now = pq.top()[0];
        int now_dist = pq.top()[1];
        pq.pop();

        if(dist[now] < now_dist) continue;
        for(vector<int> d : bus[now]){
            int next = d[0];
            int next_dist = dist[now] + d[1];
            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next, next_dist});
                prv[next] = now;
            }
        }
    }
}

int main(){
    FASTIO

    int n, m, start, end;
    cin >> n >> m;

    bus = vector<vector<vector<int>>>(n + 1);
    dist = vector<int>(n + 1, inf);
    prv = vector<int>(n + 1, inf);
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        bus[a].push_back({b, cost});
    }

    cin >> start >> end;

    dijkstra(start);
    
    int now = end;

    vector<int> course;
    while(now != start){
        course.push_back(now);
        now = prv[now];
    }
    course.push_back(start);

    cout << dist[end] << "\n" << course.size() << "\n";
    for(int i = course.size() - 1; i >= 0; i--) cout << course[i] << " ";

    return 0;
}