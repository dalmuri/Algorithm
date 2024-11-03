#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int inf = 123456789;

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items(n + 1);
    for(int i = 1; i <= n; i++) cin >> items[i];

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, inf));
    for(int i = 0; i < r; i++){
        int a, b, l;
        cin >> a >> b >> l;

        dist[a][b] = l;
        dist[b][a] = l;
    }
    for(int i = 1; i <= n; i++) dist[i][i] = 0;

    for(int mid = 1; mid <= n; mid++){
        for(int start = 1; start <= n; start++){
            for(int end = 1; end <= n; end++){
                dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end]);
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        int item = 0;
        for(int j = 1; j <= n; j++){
            if(dist[i][j] <= m) item += items[j];
        }

        answer = max(answer, item);
    }

    cout << answer;

    return 0;
}