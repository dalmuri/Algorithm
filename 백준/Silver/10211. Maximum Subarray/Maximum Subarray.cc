#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int arr[1000];
int dp[1000];

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) cin >> arr[i];

        dp[0] = arr[0];
        int answer = arr[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(0, dp[i - 1]) + arr[i];
            answer = max(answer, dp[i]);
        }

        cout << answer << "\n";
    }

    return 0;
}