#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> people(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> people[i][0] >> people[i][1];
    
    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = 0; j < n; j++){
            if(people[i][0] < people[j][0] && people[i][1] < people[j][1]) cnt++;
        }

        cout << cnt << " ";
    }    

    return 0;
}