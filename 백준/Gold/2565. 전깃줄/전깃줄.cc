#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> lines;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        lines.push_back({a, b});
    }

    sort(lines.begin(), lines.end());

    vector<int> dp(lines.size(), 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(lines[j][1] < lines[i][1]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << n - *max_element(dp.begin(), dp.end());

    return 0;
}