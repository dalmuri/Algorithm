#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 987654321;

vector<int> get_dist(int start, int n, vector<vector<vector<int>>>& roads){
    vector<int> dist(n + 1, inf);
    dist[start] = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        auto [now_dist, now] = pq.top();
        pq.pop();

        if(now_dist > dist[now]) continue;
        for(vector<int> road : roads[now]){
            int next = road[0];
            int next_dist = now_dist + road[1];

            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    return dist;
} 

int main(){
    FASTIO

    int T;
    cin >> T;
    while(T--){
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;

        vector<vector<vector<int>>> roads(n + 1);
        int gh;
        for(int i = 0; i < m; i++){
            int a, b, d;
            cin >> a >> b >> d;

            roads[a].push_back({b, d});
            roads[b].push_back({a, d});

            if((a == g && b == h) || (a == h && b == g)) gh = d;
        }

        vector<int> dests(t);
        for(int i = 0; i < t; i++) cin >> dests[i];
        sort(dests.begin(), dests.end());

        vector<int> dist_s = get_dist(s, n, roads);
        vector<int> dist_g = get_dist(g, n, roads);
        vector<int> dist_h = get_dist(h, n, roads);

        for(int dest : dests){
            if(dist_s[dest] == min(dist_s[g] + gh + dist_h[dest], dist_s[h] + gh + dist_g[dest])){
                cout << dest << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}