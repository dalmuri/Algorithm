#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;

    while(t--){
        string n, m;
        cin >> n >> m;

        vector<int> diff(2, 0);
        for(int j = 0; j < n.size(); ++j){
            if(n[j] != m[j]) diff[n[j] - '0']++;
        }

        cout << *max_element(diff.begin(), diff.end()) << "\n";
    }

    return 0;
}