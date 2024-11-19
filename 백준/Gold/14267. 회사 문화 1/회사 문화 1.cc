#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int superiors[100'001];
int compliment[100'001];

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> superiors[i];

    for(int i = 0; i < m; i++){
        int worker, value;
        cin >> worker >> value;

        compliment[worker] += value;
    }

    for(int i = 1; i <= n; i++){
        if(superiors[i] != -1) compliment[i] += compliment[superiors[i]];
        cout << compliment[i] << " ";
    }

    return 0;
}