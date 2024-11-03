#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int inf = 123456789;

bool bellman_ford(int n, vector<vector<int>>& cities){
    vector<int> dist(n + 1, 0);

    for(int i = 0; i < n; i++){
        for(int s = 1; s <= n; s++){
            for(int e = 1; e <= n; e++){
                if(dist[s] < inf && cities[s][e] < inf && dist[s] + cities[s][e] < dist[e]){
                    dist[e] = dist[s] + cities[s][e];

                    if(i == n - 1) return true;
                }
            }
        }
    }

    return false;
}

int main(){
    FASTIO

    int tc;
    cin >> tc;
    while(tc--){
        int n, m, w;
        cin >> n >> m >> w;

        vector<vector<int>> cities(n + 1, vector<int>(n + 1, inf));
        for(int i = 0; i < m; i++){
            int s, e, t;
            cin >> s >> e >> t;

            cities[s][e] = min(cities[s][e], t);
            cities[e][s] = min(cities[e][s], t);
        }
        for(int i = 0; i < w; i++){
            int s, e, t;
            cin >> s >> e >> t;

            cities[s][e] = min(cities[s][e], -t);
        }

        cout << (bellman_ford(n, cities) ? "YES\n" : "NO\n");
    }

    return 0;
}