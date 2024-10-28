#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n, m;
        cin >> n >> m;

        vector<int> docs(n);
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            cin >> docs[i];

            q.push({docs[i], i});
        }

        sort(docs.rbegin(), docs.rend());

        int cnt = 1;
        for(int i = 0; i < n; i++, cnt++){
            while(q.front().first != docs[i]){
                q.push(q.front());
                q.pop();
            }

            if(q.front().second == m){
                cout << cnt << "\n";
                break;
            }
            q.pop();
        }
    }

    return 0;
}