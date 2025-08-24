#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    long long l;
    int n, k;
    cin >> l >> n >> k;

    vector<long long> lamps(n);
    for(int i = 0; i < n; ++i) cin >> lamps[i];

    long long light = 0ll;
    map<long long, bool> visited;
    for(int cnt = 0; cnt < k; ++light){
        for(int i = 0; i < n && cnt < k; ++i){
            if(lamps[i] - light >= 0 && !visited[lamps[i] - light]){
                visited[lamps[i] - light] = true;
                cout << light << "\n";
                cnt++;
            }

            if(lamps[i] + light <= l && !visited[lamps[i] + light] && cnt < k){
                visited[lamps[i] + light] = true;
                cout << light << "\n";
                cnt++;
            }
        }
    }

    return 0;
}