#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int inf = 100;

using namespace std;

int main() {
    FASTIO;
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, inf));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    // Floyd Warshall
    for(int mid = 1; mid <= n; mid++){
        dist[mid][mid] = 0;
        for(int start = 1; start <= n; start++){
            for(int end = 1; end <= n; end++){
                dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end]);
            }
        }
    }

    int min_bacon = accumulate(dist[1].begin() + 1, dist[1].end(), 0);
    int answer = 1;
    for(int i = 2; i <= n; i++){
        int bacon = accumulate(dist[i].begin() + 1, dist[i].end(), 0);
        if(bacon < min_bacon){
            min_bacon = bacon;
            answer = i;
        }
    }

    cout << answer << endl;
    
    return 0;
}