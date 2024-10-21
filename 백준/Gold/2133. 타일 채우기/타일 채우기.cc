#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<int> dp;

int calc(int width){
    if(width & 1) return 0;
    if(dp[width]) return dp[width];

    dp[width] = calc(width - 2) * 3;

    for(int i = 4; i <= width; i+=2){
        dp[width] += calc(width - i) * 2;
    }

    return dp[width];
}

int main(){
    FASTIO

    cin >> n;
    dp = vector<int>(n + 1, 0);
    dp[0] = 1;
    dp[2] = 3;

    cout << calc(n);

    return 0;
}