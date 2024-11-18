#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> children[100'001];
int costs[100'001][2];
long long dp[100'001][2];

long long calc(int node, int color){
    if(dp[node][color] > 0) return dp[node][color];

    dp[node][color] = costs[node][color];
    if(color == 1){ // black
        for(int child : children[node]){
            dp[node][color] += calc(child, 0);
        }
    }
    else{ // white
        for(int child : children[node]){
            dp[node][color] += min(calc(child, 0), calc(child, 1));
        }
    }

    return dp[node][color];
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int p, c;
        cin >> p >> c;

        children[p].push_back(c);
    }
    for(int i = 0; i < n; i++) cin >> costs[i][0] >> costs[i][1];

    cout << min(calc(0, 0), calc(0, 1));

    return 0;
}