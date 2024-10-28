#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> coordinates(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> coordinates[i][0] >> coordinates[i][1];

    sort(coordinates.begin(), coordinates.end());

    for(vector<int> coordinate : coordinates) cout << coordinate[0] << " " << coordinate[1] << "\n";

    return 0;
}