#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> juniors[100'001];
int sum[100'001];
bool visited[100'001];

void compliment(int worker, int superior){
    if(visited[worker]) return;
    visited[worker] = true;

    sum[worker] += sum[superior];

    for(int junior : juniors[worker]){
        compliment(junior, worker);
    }
}

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int superior;
        cin >> superior;
        if(superior == -1) continue;

        juniors[superior].push_back(i);
    }

    for(int i = 0; i < m; i++){
        int worker, value;
        cin >> worker >> value;

        sum[worker] += value;
    }

    for(int i = 1; i <= n; i++){
        compliment(i, 0);
        cout << sum[i] << " ";
    }

    return 0;
}