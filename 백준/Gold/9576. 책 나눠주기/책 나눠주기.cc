#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<bool> visited(n + 1, false);
        vector<pair<int, int>> books(m);
        for(int i = 0; i < m; ++i) cin >> books[i].first >> books[i].second;

        sort(books.begin(), books.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        int answer = 0;
        for(int i = 0; i < m; ++i){
            for(int j = books[i].first; j <= books[i].second; ++j){
                if(!visited[j]){
                    visited[j] = true;
                    answer++;
                    break;
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}