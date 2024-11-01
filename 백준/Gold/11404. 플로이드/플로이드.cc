#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int main(){
    FASTIO

    int inf = 123456789;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, inf));
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        
        dist[a][b] = min(dist[a][b], cost);
    }

    for(int mid = 1; mid <= n; mid++){
        for(int start = 1; start <= n; start++){
            for(int end = 1; end <= n; end++){
                dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << (dist[i][j] != inf ? dist[i][j] : 0) << " ";
        }
        cout << "\n";
    }

    return 0;
}