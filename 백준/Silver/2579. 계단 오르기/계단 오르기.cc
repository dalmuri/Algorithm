#include <iostream>
#include <string>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){
    FASTIO;
    
    int n;
    cin >> n;

    vector<int> point(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> point[i];
    }

    vector<vector<int>> stair(n + 1, vector<int>(2, 0));
    stair[1][0] = point[1];
    stair[1][1] = point[1];

    for(int i = 2; i <= n; i++){
        stair[i][0] = max(stair[i - 2][0], stair[i - 2][1]) + point[i];
        stair[i][1] = stair[i - 1][0] + point[i];
    }

    cout << max(stair[n][0], stair[n][1]) << endl;
    
    return 0;
}