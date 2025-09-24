#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": ";

        int n;
        cin >> n;

        vector<int> prices(n * 2);
        vector<bool> visited(n * 2, false);
        for(int i = 0; i < n * 2; ++i) cin >> prices[i];

        for(int i = 0; i < n * 2; ++i){
            if(visited[i]) continue;

            cout << prices[i] << " ";
            int idx = lower_bound(prices.begin() + i + 1, prices.end(), prices[i] / 3 * 4) - prices.begin();
            while(visited[idx]) idx++;
            visited[idx] = true;
        }

        cout << "\n";
    }

    return 0;
}