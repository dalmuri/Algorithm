#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    for(int mid = 0; mid < n; mid++){
        for(int start = 0; start < n; start++){
            for(int end = 0; end < n; end++){
                if(graph[start][mid] + graph[mid][end] >= 2) graph[start][end] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << graph[i][j] << " ";
        cout << "\n";
    }

    return 0;
}