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

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> b(m);
        for(int i = 0; i < m; i++) cin >> b[i];

        sort(b.begin(), b.end());

        int answer = 0;
        for(int i = 0; i < n; i++){
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            answer += idx;
        }

        cout << answer << "\n";
    }

    return 0;
}