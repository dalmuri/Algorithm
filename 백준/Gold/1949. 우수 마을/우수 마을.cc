#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int cities[10'001];
vector<int> edges[10'001];
int dp[10'001][2];

int sum(int node, int parent, int includes){
    if(dp[node][includes] > 0) return dp[node][includes];
    int res = includes ? cities[node] : 0;
    
    for(int child : edges[node]){
        if(child == parent) continue;

        if(includes) res += sum(child, node, 0);
        else res += max(sum(child, node, 0), sum(child, node, 1));
    }

    return dp[node][includes] = res;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> cities[i];

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout << max(sum(1, -1, 0), sum(1, -1, 1));

    return 0;
}